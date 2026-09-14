memory = []
max_size = 10

def allocate(size, mem = memory, max_s = max_size):
    if len(mem) == 0:
        if size <= max_s:
            mem.append([0, size])
            return 0
        return -1
    if mem[0][0] >= size:
        mem.insert(0, [0,size])
        return 0
    for i in range(len(mem)-1):
        space = mem[i+1][0]-(mem[i][0]+mem[i][1])
        if space >= size:
            mem.insert(i+1, [mem[i][0]+mem[i][1], size])
            return mem[i+1][0]
    if max_s - (mem[-1][0] + mem[-1][1]) >= size:
        mem.append([mem[-1][0]+mem[-1][1], size])
        return mem[-1][0]
    return -1

def free(n, mem = memory):
    for i in range(len(mem)):
        if mem[i][0] == n:
            del mem[i]
            return 0
    return -1


print(allocate(2))
print(allocate(3))
print(allocate(2))
print(free(2))
print(memory)
print(allocate(2))
print(memory)