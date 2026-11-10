import re, sys

temp_count = 1
label_count = 1

PRIOR = {"+": 1, "-": 1, "*": 2, "/": 2}
OPS = {"+": "ADD", "-": "SUB", "*": "MUL", "/": "DIV"}

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
        
        self.weight = 0
        self.temp_var = None

def get_temp():
	global temp_count
	temp = f"t{temp_count}"
	temp_count += 1
	return temp


def get_label():
	global label_count
	label = f"L{label_count}"
	label_count += 1
	return label

def tokenize(text):
	pattern = r'(whilenot|while|ifnot|if|read>|write>|[a-zA-Z_][a-zA-Z0-9_]*|[0-9]+(?:\.[0-9]+)?|[\[\]{};=+\-*/()])'
	return [token.strip() for token in re.findall(pattern, text) if token.strip()]

def parse_expression_to_ast(tokens):
    expr_tokens = []
    while tokens and tokens[0] not in (']', ';', '{'):
        expr_tokens.append(tokens.pop(0))
    
    stack = []
    queue = []
    for part in expr_tokens:
        if part in PRIOR:
            while stack and stack[-1] != "(" and PRIOR.get(stack[-1], 0) >= PRIOR[part]:
                queue.append(stack.pop())
            stack.append(part)
        elif part == "(":
            stack.append(part)
        elif part == ")":
            while stack and stack[-1] != "(":
                queue.append(stack.pop())
            if stack:
                stack.pop()
        else:
            queue.append(part)
            
    while stack:
        queue.append(stack.pop())

    ast_stack = []
    for part in queue:
        if part in PRIOR:
            right_node = ast_stack.pop()
            left_node = ast_stack.pop()
            ast_stack.append(Node(part, left_node, right_node))
        else:
            ast_stack.append(Node(part))

    return ast_stack[0]

def optimize_ast(node, cache):
    if not node:
        return None
    
    node.left = optimize_ast(node.left, cache)
    node.right = optimize_ast(node.right, cache)
    
    if not node.left and not node.right:
        signature = f"LEAF_{node.value}"
    else:
        left_id = id(node.left)
        right_id = id(node.right)
        if node.value in ('+', '*'):
            if left_id > right_id:
                left_id, right_id = right_id, left_id
        signature = f"OP_{node.value}_{left_id}_{right_id}"
        
    if signature in cache:
        return cache[signature]
    else:
        cache[signature] = node
        return node

def calc_weight(node):
    if not node: return 0
    
    if not node.left and not node.right:
        node.weight = 1
        return 1
        
    l_weight = calc_weight(node.left)
    r_weight = calc_weight(node.right)
    
    if l_weight == r_weight:
        node.weight = l_weight + 1
    else:
        node.weight = max(l_weight, r_weight)
        
    return node.weight

def generate_code(node, insts):
    if not node.left and not node.right:
        return node.value
        
    if node.temp_var is not None:
        return node.temp_var

    if node.left.weight >= node.right.weight:
        left_res = generate_code(node.left, insts)
        right_res = generate_code(node.right, insts)
    else:
        right_res = generate_code(node.right, insts)
        left_res = generate_code(node.left, insts)

    dest = get_temp()
    op_name = OPS[node.value]
    insts.append(f"{op_name} {left_res} {right_res} {dest}")
    
    node.temp_var = dest
    return dest

def parse_expression(tokens):
    global temp_count
    
    root = parse_expression_to_ast(tokens)
    temp_count = 1
    
    root = optimize_ast(root, {})
    calc_weight(root)
    
    insts = []
    res = generate_code(root, insts)
    
    return insts, res


def parse_block(tokens):
	instructions = []

	while tokens:
		token = tokens[0]

		if token == ";":
			tokens.pop(0)
			continue

		if token == "read>":
			tokens.pop(0)
			variable = tokens.pop(0)
			instructions.append(f"READ {variable}")
			if tokens and tokens[0] == ";":
				tokens.pop(0)

		elif token == "write>":
			tokens.pop(0)
			variable = tokens.pop(0)
			instructions.append(f"WRITE {variable}")
			if tokens and tokens[0] == ";":
				tokens.pop(0)

		elif token in ("if", "ifnot", "while", "whilenot"):
			keyword = tokens.pop(0)
			if tokens and tokens[0] == "[":
				tokens.pop(0)

			expression_instructions, result = parse_expression(tokens)

			if tokens and tokens[0] == "]":
				tokens.pop(0)
			if tokens and tokens[0] == "{":
				tokens.pop(0)

			if keyword == "if":
				end_label = get_label()
				instructions.extend(expression_instructions)
				instructions.append(f"GOTOIFNOT {result} {end_label}")
				instructions.extend(parse_block(tokens))
				instructions.append(f"LABEL {end_label}")

			elif keyword == "ifnot":
				end_label = get_label()
				instructions.extend(expression_instructions)
				instructions.append(f"GOTOIF {result} {end_label}")
				instructions.extend(parse_block(tokens))
				instructions.append(f"LABEL {end_label}")

			else:
				start_label = get_label()
				end_label = get_label()
				instructions.append(f"LABEL {start_label}")
				instructions.extend(expression_instructions)

				if keyword == "while":
					instructions.append(f"GOTOIFNOT {result} {end_label}")
				else:
					instructions.append(f"GOTOIF {result} {end_label}")

				instructions.extend(parse_block(tokens))
				instructions.append(f"GOTO {start_label}")
				instructions.append(f"LABEL {end_label}")

		elif len(tokens) > 1 and tokens[1] == "=":
			dest = tokens.pop(0)
			tokens.pop(0)
			expression_instructions, result = parse_expression(tokens)
			instructions.extend(expression_instructions)

			if not expression_instructions:
				instructions.append(f"COPY {result} {dest}")
			else:
				last_instruction = instructions[-1]
				parts = last_instruction.split()
				if len(parts) == 4:
					parts[3] = dest
					instructions[-1] = " ".join(parts)

			if tokens and tokens[0] == ";":
				tokens.pop(0)

		elif token == "}":
			tokens.pop(0)
			break
		else:
			tokens.pop(0)

	return instructions

def resolve_labels(instructions):
	final_instructions = []
	label_map = {}
	line_number = 0

	for instruction in instructions:
		if instruction.startswith("LABEL "):
			label_name = instruction.split()[1]
			label_map[label_name] = line_number
		else:
			line_number += 1

	for instruction in instructions:
		if instruction.startswith("LABEL "):
			continue
		parts = instruction.split()
		if parts[0] in ("GOTO", "GOTOIF", "GOTOIFNOT"):
			label_name = parts[-1]
			if label_name in label_map:
				parts[-1] = str(label_map[label_name])
				instruction = " ".join(parts)
		final_instructions.append(instruction)

	return final_instructions

arguments = sys.argv[1:]
if arguments:
	file_path = arguments[0]
	dest_path = arguments[1] if len(arguments) > 1 else file_path[:file_path.find(".")] + ".pasm"
	with open(file_path, "r") as source_file:
		text = source_file.read()
	tokens = tokenize(text)
	compiled_instructions = parse_block(tokens)
	final_code = resolve_labels(compiled_instructions)
	with open(dest_path, "w") as output_file:
		for instruction in final_code:
			output_file.write(instruction + "\n")
