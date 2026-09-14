mem = []
max_s = 0
max_l = 0

def malloc(size, mem=mem):
    if size <= 0:
        return -1
        
    if not mem:
        if size <= max_s:
            mem.append([0, size])
            return 0
        return -1

    if mem[0][0] >= size:
        mem.insert(0, [0, size])
        return 0

    for i in range(1, len(mem)):
        space = mem[i][0] - (mem[i-1][0] + mem[i-1][1])
        if space >= size:
            mem.insert(i, [mem[i-1][0] + mem[i-1][1], size])
            return mem[i][0]

    last_end = mem[-1][0] + mem[-1][1]
    if (max_s - last_end) >= size:
        mem.append([last_end, size])
        return last_end
    return -1

def free(ind, mem=mem):
    for i in range(len(mem)):
        if mem[i][0] == ind:
            del mem[i]
            return

def pprint(mem=mem):
    line = ''
    last_end = 0
    
    for i in range(len(mem)):
        start_idx = mem[i][0]
        size = mem[i][1]
        
        if start_idx > last_end:
            empty_space = start_idx - last_end
            line += ' ' * (empty_space * 2)
            
        block_str = str(start_idx)
        x_count = size * 2 - len(block_str) - 1
        
        if x_count < 0: 
            x_count = 0
            
        block_str += 'x' * x_count + '|'
        
        line += block_str
        last_end = start_idx + size
        
    if last_end < max_s:
        empty_space = max_s - last_end
        line += ' ' * (empty_space * 2 - 1) + '|'
        
    lines = [line[i:i + max_l*2] for i in range(0, len(line), max_l*2)]
    
    for i in range(len(lines)):
        if len(lines[i]) > 0:
            lines[i] = lines[i][:-1] + '|'
        print('|', lines[i], sep='')



print("Please set memory size and max output width:")
a = input("> ")
max_s = int(a.split()[0])
max_l = int(a.split()[1])

while True:
    a = input(">").strip()
    if not a:
        continue
            
    parts = a.split()
    
    if parts[0] == 'allocate':
        res = malloc(int(parts[1]))
        print(res) 
        
    elif parts[0] == 'free':
        free(int(parts[1]))
        
    elif parts[0] == 'print':
        pprint()
        
    elif parts[0] == 'help':
        print("Available commands:\n")
        print("  help    - show this help")
        print("  exit    - exit this program")
        print("  print   - print memory blocks map")
        print("  allocate <num> - allocate <num> cells. Returns block first cell number")
        print("  free <num> - free block with first cell number <num>")
        
    elif parts[0] == 'exit':
        break