from collections import deque

N, M = map(int, input().split())

answer = 0
laboratory = []
for i in range(N):
    arr = list(map(int, input().split()))
    laboratory.append(arr)

dx = [1 , 0, -1, 0]
dy = [0, -1, 0, 1]

def bfs(labor):
    temp = [[labor[i][j] for j in range(M)] for i in range(N)]
    q = deque()

    for i in range(N):
        for j in range(M):
            if temp[i][j] == 2:
                q.append((i, j))

    while q:
        Y, X =  q.popleft()
        for i in range(4):
            aY = Y + dy[i]
            bX = X + dx[i]

            if aY < 0 or aY >= N or bX < 0 or bX >= M:
                continue
            if temp[aY][bX] == 0 :
                temp[aY][bX] = 2
                q.append((aY, bX))
    
    res = 0
    for i in range(N):
        res += temp[i].count(0)
    return res

def checking(labor, dept):
    global answer

    if dept == 3:
        answer = max(answer, bfs(labor))
    else:
        for i in range(N):
            for j in range(M):
                if labor[i][j] == 0:
                    labor[i][j] = 1
                    checking(labor, dept + 1)
                    labor[i][j] = 0
        
checking(laboratory, 0)
print(answer)