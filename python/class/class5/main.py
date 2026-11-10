class Route:
    def __init__(self, dist:float, start:str, end:str, count:int):
        self.dist = dist
        self.start = start
        self.end = end
        self.count = count

    def av_dist(self):
        return self.dist / (self.count - 1)

    def __str__(self):
        return(f"{self.dist} {self.start} {self.end} {self.count}")

    def __gt__(self, n):
        return self.dist > n.dist

X = 10
XX = "Lviv"

tr = []

with open("file.txt", "r") as f:
    while True:
        data = f.readline()
        if not data: break
        data = data.split()
        tr.append(Route(float(data[0]), data[1], data[2], int(data[3])))

tr = sorted(tr, key = lambda el: el.dist)
print(*(i for i in tr), "", sep = "\n")

print(*(i for i in tr if i.av_dist() < X), "", sep = "\n")

tr2 = [i for i in tr if i.start == XX]
print(*(i for i in tr2), "", sep = "\n")

max = tr[0].count

for i in range(1, len(tr)):
    if tr[i].count > max: max = tr[i].count

max = [tr[0]]
for i in tr[1:]:
    if max[0].count < i.count:
        max.clear()
        max.append(i)
    elif max[0].count == i.count:
        max.append(i)

print(*(i for i in max), sep = "\n")