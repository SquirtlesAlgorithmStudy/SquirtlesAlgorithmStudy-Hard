import sys
from itertools import combinations

input = sys.stdin.readline

N, K = map(int, input().split())
coordinates = [tuple(map(int, input().split())) for _ in range(N)]

D = [[0] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if i == j:
            D[i][j] = 0
        else:
            D[i][j] = abs(coordinates[i][0] - coordinates[j][0]) + abs(
                coordinates[i][1] - coordinates[j][1]
            )
            D[j][i] = D[i][j]

ans = float("inf")
for item in combinations(range(N), K):
    temp = []
    for i in range(N):
        temp_val = float("inf")
        for it in item:
            temp_val = min(temp_val, D[it][i])
        temp.append(temp_val)
    ans = min(ans, max(temp))

print(ans)
