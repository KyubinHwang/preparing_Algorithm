from sys import stdin

N, M = map(int, stdin.readline().split())
arr = [[0] * (N + 1)]

for _ in range(N):
    a = [0] + list(map(int, stdin.readline().split()))
    arr.append(a)

for i in range(1, N + 1):
    for j in range(1, N):
        arr[i][j + 1] += arr[i][j]

for i in range(1, N + 1):
    for j in range(1, N):
        arr[j + 1][i] += arr[j][i]

for _ in range(M):
    x1, y1, x2, y2 = map(int, stdin.readline().split())
    print(arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1])