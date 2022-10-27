N = int(input())

dp = [0] * 10001

dp[0] = 1
dp[2] = 1

for i in range(4, N + 1, 2):
    for j in range(2, i + 1, 2):
        dp[i] += (dp[j - 2] * dp[i - j]) % 987654321 
        dp[i] = dp[i] % 987654321

print(dp[N])