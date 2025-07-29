import sys

input = sys.stdin.readline

N = int(input())

dp = [i for i in range(N + 1)]
if N == 1 or N == 2:
    print(dp[N])

else:
    for i in range(3, N + 1):
        dp[i] = max(dp[i], max(((j - 1) * dp[i - j]) for j in range(2, i)))

    print(dp[-1])
