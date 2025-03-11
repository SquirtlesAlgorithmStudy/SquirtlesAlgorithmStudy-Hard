import sys;sys.setrecursionlimit(1<<30)
input = open(0).readline
N, M = map(int, input().split())
S = input().rstrip()
graph = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    u, v, c = input().split()
    u, v = int(u), int(v)
    graph[u].append((v, c))
    graph[v].append((u, c))
visited = [False] * (N + 1)
LCS = [[0] * (M + 1) for _ in range(5000)]
mx = 0
def dfs(depth, u):
    global mx
    visited[u] = True
    for v, c in graph[u]:
        if visited[v]:
            continue
        for i in range(M):
            if S[i] == c:
                LCS[depth + 1][i + 1] = LCS[depth][i] + 1
            else:
                LCS[depth + 1][i + 1] = max(LCS[depth][i + 1], LCS[depth + 1][i])
        mx = max(mx, LCS[depth + 1][-1])
        dfs(depth + 1, v)
dfs(0, 1)
print(mx)
