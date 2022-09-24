import sys
from collections import deque
input = sys.stdin.readline
N, M = map(int, input().split())
wall = [list(map(str, input().rstrip())) for _ in range(N)]


dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

def bfs():
    q = deque()
    q.append((0, 0, 0))
    visited = [[[0] * 2 for _ in range(M)] for _ in range(N)]
    visited[0][0][0] = 1

    while q:   
        y, x, z = q.popleft()
        if y == N - 1 and x == M - 1:
            return visited[y][x][z]
        
        for i in range(4):
            Y = y + dy[i]
            X = x + dx[i]
            if Y >= N or Y < 0 or X >= M or X < 0:
                continue
            
            if wall[Y][X] == '0' and visited[Y][X][z] == 0:
                visited[Y][X][z] = visited[y][x][z] + 1
                q.append((Y, X, z))
            elif wall[Y][X] == '1' and z == 0:
                visited[Y][X][1] = visited[y][x][0] + 1
                q.append((Y, X, 1))

            

    return -1

print(bfs())