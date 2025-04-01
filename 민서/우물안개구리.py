input = open(0).readline
N, M = map(int, input().split())
weight = [0, *map(int, input().split())]
rank = [0] * (N + 1)
for _ in range(M):
    a, b = map(int, input().split())
    rank[a] += 1
    if weight[a] > weight[b]:
        rank[a] -= 1
    rank[b] += 1
    if weight[b] > weight[a]:
        rank[b] -= 1
ans = 0
for r in rank[1:]:
    if r == 0:
        ans += 1
print(ans)
