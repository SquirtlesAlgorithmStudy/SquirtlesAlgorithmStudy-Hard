def solution(sticker):
    if len(sticker) == 1:
        return sticker[0]
    elif len(sticker) == 2:
        return max(sticker)

    dp = [[0] * 4 for _ in range(len(sticker))]
    dp[0][0] = 0
    dp[0][1] = 0
    dp[2][2] = sticker[0]
    dp[2][3] = sticker[0] + sticker[2]

    for i in range(1, len(sticker)):
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
        dp[i][1] = dp[i - 1][0] + sticker[i]

    if len(sticker) > 3:
        for i in range(3, len(sticker)):
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][3])
            dp[i][3] = dp[i - 1][2] + sticker[i]

    answer = max(dp[-1][0], dp[-1][1], dp[-1][2])

    return answer
