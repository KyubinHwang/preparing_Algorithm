def solution(triangle):
    answer = 0
    dp = [[0 for _ in range(i + 1)] for i in range(len(triangle))]

    dp[0][0] = triangle[0][0]

    for i in range(1, len(triangle)):
        length = triangle[i]
        for j in range(len(length)):
            if j == 0:
                dp[i][j] = dp[i - 1][j] + length[j]
            elif j == len(length) - 1:
                dp[i][j] = dp[i - 1][j - 1] + length[j]
            else:
                dp[i][j] = max(dp[i - 1][j - 1] + length[j], dp[i - 1][j] + length[j])

    return max(dp[len(triangle) - 1])