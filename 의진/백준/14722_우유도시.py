import sys

input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

dp = [[[0] * N for _ in range(N)] for _ in range(3)]

dp[0][0][0] = 1 if board[0][0] == 0 else 0
dp[1][0][0] = 0
dp[2][0][0] = 0

for r in range(N):
    for c in range(N):
        now = board[r][c]
        valid = (now - 1) % 3
        if now == 0:
            if r > 0:
                dp[now][r][c] = max(
                    dp[valid][r - 1][c] + 1, dp[now][r - 1][c], dp[now][r][c]
                )
            if c > 0:
                dp[now][r][c] = max(
                    dp[valid][r][c - 1] + 1, dp[now][r][c - 1], dp[now][r][c]
                )
        else:
            if r > 0:
                dp[now][r][c] = max(dp[now][r - 1][c], dp[now][r][c])
                if dp[valid][r - 1][c] > 0:
                    dp[now][r][c] = max(dp[valid][r - 1][c] + 1, dp[now][r][c])
            if c > 0:
                dp[now][r][c] = max(dp[now][r][c - 1], dp[now][r][c])
                if dp[valid][r][c - 1] > 0:
                    dp[now][r][c] = max(dp[valid][r][c - 1] + 1, dp[now][r][c])

        for i in range(1, 3):
            if r > 0:
                dp[(now + i) % 3][r][c] = max(
                    dp[(now + i) % 3][r][c], dp[((now + i) % 3)][r - 1][c]
                )

            if c > 0:
                dp[(now + i) % 3][r][c] = max(
                    dp[(now + i) % 3][r][c], dp[((now + i) % 3)][r][c - 1]
                )

print(max(dp[0][-1][-1], dp[1][-1][-1], dp[2][-1][-1]))
