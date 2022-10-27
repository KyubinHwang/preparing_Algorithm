from itertools import combinations

N, M  = map(int, input().split())

A = list(map(int, input().split()))
A2 = []
dp = [0] * M

sum = 0
for i in range(N):
    sum += A[i]
    A2.append(sum)

for a in A2:
    dp[a % M] += 1

answer = dp[0]

for i in dp:
    answer += i * (i - 1) // 2

print(answer)