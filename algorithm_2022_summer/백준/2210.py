import sys
input = sys.stdin.readline

board = [list(map(str, input().split())) for _ in range(5)]
x = [1, 0, -1, 0]
y = [0, -1, 0, 1]
arr = set()

def DFS (i, j, num):
    num += board[i][j]
    if len(num) == 6:
        arr.add(num)
        return      

    for t in range(4):
        dx = x[t] + j
        dy = y[t] + i
        if 0 <= dy < 5 and 0 <= dx < 5:
            DFS(dy, dx, num)

for i in range(5):
    for j in range(5):
        DFS(i, j, "")

print(len(arr))