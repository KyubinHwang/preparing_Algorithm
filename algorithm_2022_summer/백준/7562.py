from collections import deque
T = int(input())

dx = [1, 2, 2, 1, -1, -2, -2, -1]
dy = [2, 1, -1, -2, -2, -1, 1, 2]

def bfs(nx, ny, fx, fy):
    q = deque()
    q.append([nx, ny])
    chess[nx][ny] = 1
    while q:
        x, y = q.popleft()
        if x == fx and y == fy:
            print(chess[fx][fy] - 1)
            return
        for i in range(8):
            X = x + dx[i]
            Y = y + dy[i]
            if 0 <= X < I and 0 <= Y < I and chess[X][Y] == 0:
                q.append([X, Y])
                chess[X][Y] = chess[x][y] + 1

for _ in range(T):
    I = int(input())
    nightX, nightY = map(int, input().split())
    findX, findY = map(int, input().split())
    chess = [[0] * I for i in range(I)]
    bfs(nightX, nightY, findX, findY)

