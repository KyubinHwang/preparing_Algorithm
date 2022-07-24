N, L = map(int, input().split())
p = list(map(int, input().split()))

p.sort()
start = p[0]
count = 1

for i in p[1:]:
    if i in range(start, start + L):
        continue
    else:
        start = i
        count += 1

print(count)