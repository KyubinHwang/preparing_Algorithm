import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, y, x):
    q = deque()
    q.append((y, x))
    graph[y][x] = 0 
    count = 1
    while q:
        Y, X = q.popleft()
        for i in range(4):
            a = Y + dy[i]
            b = X + dx[i]
            if a < 0 or a >= n or b < 0 or b >= m :
                continue
            if graph[a][b] == 1:
                q.append((a, b)) 
                count += 1
                graph[a][b] = 0 
    
    return count



n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
result = []

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            result.append(bfs(graph, i, j))

if len(result) == 0:
    print(len(result))
    print(0)
else: 
    print(len(result))
    print(max(result))