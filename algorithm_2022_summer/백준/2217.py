N = int(input())

rope = []
findMax = []
for i in range(N) :
    weight = int(input())
    rope.append(weight)

rope.sort(reverse=True)

for i in range(N) :
    findMax.append(rope[i] * (i + 1))
print(max(findMax)) 