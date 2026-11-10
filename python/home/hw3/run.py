import sys, re

variables = {}
functions = {
            "READ": lambda var: read(var),
            "WRITE": lambda var: write(var),
            "ADD": lambda n1, n2, d: add(n1, n2, d),
            "SUB": lambda n1, n2, d: sub(n1, n2, d),
            "MUL": lambda n1, n2, d: mul(n1, n2, d),
            "DIV": lambda n1, n2, d: div(n1, n2, d),
            "COPY": lambda n1, d: copy(n1, d)
            }

def add_variable(var, value = None):
    variables[var] = value

def read_variable(var):
    return variables.get(var)

def get_value(var):
    try:
        return float(var)
    except ValueError:
        return float(read_variable(var))

def read(var):
    add_variable(var, input())

def write(var):
    print(get_value(var))

def div(n1, n2, dest):
    add_variable(dest, get_value(n1) / get_value(n2))

def sub(n1, n2, dest):
    add_variable(dest, get_value(n1) - get_value(n2))

def add(n1, n2, dest):
    add_variable(dest, get_value(n1) + get_value(n2))

def mul(n1, n2, dest):
    add_variable(dest, get_value(n1) * get_value(n2))

def copy(n1, dest):
    add_variable(dest, get_value(n1))

def tokenize(text):
    pattern = r'(GOTOIFNOT|GOTOIF|GOTO|READ|WRITE|COPY|ADD|SUM|MUL|DIV|[a-zA-Z_][a-zA-Z0-9_]*|[0-9]+(?:\.[0-9]+)?|)'
    temp = []
    for i in text:
        temp.append([token.strip() for token in re.findall(pattern, i) if token.strip()])
    return temp

def run(coms):
    i = 0
    while i < len(coms):
        command = coms[i][0]
        if command in functions:
            functions[command](*(j for j in coms[i][1:]))
        elif command == "GOTO":
            i = int(coms[i][1]) - 1
        elif command == "GOTOIF" and get_value(coms[i][1]) > 0:
            i = int(coms[i][2]) - 1
        elif command == "GOTOIFNOT" and get_value(coms[i][1]) <= 0:
                    i = int(coms[i][2]) - 1
        i += 1

sys.argv = sys.argv[1:]
if sys.argv:
    text = []
    with open(sys.argv[0], "r") as fin:
        while True:
            line = fin.readline()
            if not line: break
            text.append(line)
    tokens = tokenize(text)
    run(tokens)
