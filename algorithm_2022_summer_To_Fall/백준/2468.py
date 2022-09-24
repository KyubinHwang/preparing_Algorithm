from collections import deque

N = int(input())
area = [list(map(int, input().split())) for _ in range(N)]

t = set()
for i in area:
    t.update(i)

t = list(t)

count = []

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

def bfs (y, x):
    q = deque()
    q.append((y, x))
    findarea[y][x] = 1
    while q:
        dY, dX = q.popleft()
        for tmp in range(4):
            Y = dY + dy[tmp]
            X = dX + dx[tmp]
            if Y < 0 or Y >= N or X < 0 or X >= N :
                continue
            if findarea[Y][X] == 0:
                findarea[Y][X] = 1
                q.append((Y, X))

for i in t:
    findarea = [[0 for _ in range(N)] for _ in range(N)]
    for j in range(N):
        for l in range(N):
            if area[j][l] <= i:
                findarea[j][l] = 1
    
    
    check = 0
    for j in range(N):
        for l in range(N):
            if findarea[j][l] == 0:
                bfs(j, l)
                check += 1
    
    count.append(check)
    
if max(count) == 0:
    print(1)
else :
    print(max(count))