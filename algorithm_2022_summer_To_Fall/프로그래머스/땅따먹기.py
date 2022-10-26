def solution(lands):
    dp = [[0 for _ in range(4)] for _ in range(len(lands))]

    dp[0][0] = lands[0][0]
    dp[0][1] = lands[0][1]
    dp[0][2] = lands[0][2]
    dp[0][3] = lands[0][3]

    for i in range(1, len(lands)):
        land = lands[i]
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + land[0]
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]) + land[1]
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]) + land[2]
        dp[i][3] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + land[3]

    return max(dp[len(lands) - 1])