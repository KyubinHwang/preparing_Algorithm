from collections import deque

N = int(input())

graph = [[] for _ in range(N + 1)]
root = [0 for _ in range(N + 1)]
root[1] = 1

for i in range (N - 1) :
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def bfs ():
    queue = deque([])
    queue.append(1)
    while queue :
        start = queue.popleft()
        for node in graph[start] :
            if root[node] == 0 :
                root[node] = start
                queue.append(node)

bfs()

for i in root[2:] :
    print(i)