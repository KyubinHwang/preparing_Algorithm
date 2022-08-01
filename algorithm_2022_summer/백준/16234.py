from collections import deque

N, L, R = map(int, input().split())
arr =  [list(map(int, input().split())) for _ in range(N)]

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

result = 0

def bfs(n, m):
    q = deque()
    q.append((n, m))
    visited[n][m] = 1
    temp = []
    temp.append((n,m))
    sumCount = 0
    count = 1
    while q :
        Y, X = q.popleft()
        sumCount += arr[Y][X]
        for i in range(4):
            y = Y + dy[i]
            x = X + dx[i]
            if y < 0 or y >= N or x < 0 or x >= N:
                continue
            if visited[y][x] == 0 and L <= abs(arr[Y][X] - arr[y][x]) <= R:
                q.append((y, x))
                visited[y][x] = 1
                temp.append((y, x))
                count += 1
    
    return temp, count, sumCount

check = True

while check :
    visited = [[0 for _ in range(N)] for _ in range(N)]
    check = False
    change = []
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0:
                temp, count, sumCount = bfs(i, j)
                if count > 1:
                    check = True
                    change.append((sumCount // count, temp))

    for i, j in change:
        for y, x in j:
            arr[y][x] = i

    if check :
        result += 1

print(result)