input = open(0).readline
N, M = map(int, input().split())
parent = [0, *map(int, input().split())]
ans = [0] * (N + 1)
for _ in range(M):
    i, w = map(int, input().split())
    ans[i] += w
for i in range(2, N + 1):
    ans[i] += ans[parent[i]]
print(*ans[1:])
