from collections import deque

S = int(input())

q = deque()
q.append((1, 0, 0))

visited = [[0] * 1001 for _ in range(1001)]

while q:
    x, count, clipBoard = q.popleft()

    if x == S :
        print(count)
        break

    if visited[x][x] == 0:
        visited[x][x] = count + 1
        q.append((x, count + 1, x))

    if x + clipBoard < 1001 and visited[x + clipBoard][clipBoard] == 0  :
        visited[x + clipBoard][clipBoard] = count + 1
        q.append((x + clipBoard, count + 1, clipBoard))

    if x > 1 and x < 1001 and visited[x - 1][clipBoard] == 0 :
        visited[x - 1][clipBoard] = count + 1
        q.append((x - 1, count + 1, clipBoard))