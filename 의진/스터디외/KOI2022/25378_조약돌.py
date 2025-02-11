import sys

input = sys.stdin.readline

N = int(input())
seq = [0] + list(map(int, input().split()))
dp = [0] * (N + 1)
dp2 = [[0] * (N + 1) for _ in range(N + 1)]

dp[1] = 1
dp2[1][1] = seq[1]

for i in range(2, N + 1):
    for j in range(1, i + 1):
        if i == j:
            dp2[j][i] = seq[i]
        else:
            if dp2[j][i - 1] == 0:
                dp2[j][i] = seq[i]
            elif dp2[j][i - 1] == -1:
                dp2[j][i] = -1
            else:
                if seq[i] - dp2[j][i - 1] >= 0:
                    dp2[j][i] = seq[i] - dp2[j][i - 1]
                else:
                    dp2[j][i] = -1
    dp[i] = dp[i - 1] + 1

    for j in range(2, i + 1):
        if dp2[i - j + 1][i] == 0:
            dp[i] = min(dp[i], dp[i - j] + j - 1)
        else:
            dp[i] = min(dp[i], dp[i - j] + j)

print(dp[-1])
