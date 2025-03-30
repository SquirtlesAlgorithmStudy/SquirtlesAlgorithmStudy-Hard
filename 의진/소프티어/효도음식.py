import sys

input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))

if n == 3:
    print(seq[0] + seq[2])
    sys.exit()

dp = [[0] * n for _ in range(2)]
dp_max = [[0] * n for _ in range(2)]
dp[0][0] = seq[0]
dp[1][-1] = seq[-1]
dp_max[0][0] = dp[0][0]
dp_max[1][-1] = dp[1][-1]


for i in range(1, n):
    dp[0][i] = max(dp[0][i - 1] + seq[i], seq[i])
    dp_max[0][i] = max(dp[0][i], dp_max[0][i - 1])

for i in range(n - 2, 0, -1):
    dp[1][i] = max(dp[1][i + 1] + seq[i], seq[i])
    dp_max[1][i] = max(dp[1][i], dp_max[1][i + 1])

ans = -float("inf")

for i in range(1, n - 1):
    ans = max(ans, dp_max[0][i - 1] + dp_max[1][i + 1])


print(ans)
