import sys
import heapq

input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))

if n == 3:
    print(seq[0] + seq[2])
    sys.exit()

dp = [[0] * n for _ in range(2)]
dp[0][0] = seq[0]
dp[1][-1] = seq[-1]


for i in range(1, n):
    dp[0][i] = max(dp[0][i - 1] + seq[i], seq[i])

for i in range(n - 2, 0, -1):
    dp[1][i] = max(dp[1][i + 1] + seq[i], seq[i])

pq1 = []
pq2 = [(-item, i + 2) for i, item in enumerate(dp[1][2:])]
heapq.heapify(pq2)
ans = 0
# print(dp)
for i in range(1, n - 1):
    heapq.heappush(pq1, -dp[0][i - 1])
    if pq2[0][1] == i:
        # print(pq2[0])
        heapq.heappop(pq2)

    ans = max(ans, -pq1[0] - pq2[0][0])


print(ans)
