N = int(input())
M = int(input())

edges = []
com = [i for i in range(0, N + 1)]
for _ in range(M):
    a, b, edge = map(int, input().split())
    edges.append([edge, a, b])

edges.sort()

def find_parent(x):
    if com[x] != x:
        com[x] = find_parent(com[x])

    return com[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)

    if a < b:
        com[b] = a
    else:
        com[a] = b

ans = 0
for edge in edges:
    if find_parent(edge[1]) != find_parent(edge[2]):
        union_parent(edge[1], edge[2])
        ans += edge[0]
print(ans)