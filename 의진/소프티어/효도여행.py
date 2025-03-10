import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M = map(int, input().split())
S = input().strip()
connections = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    a, b, c = input().strip().split()
    a = int(a)
    b = int(b)
    connections[a].append((b, c))
    connections[b].append((a, c))


visited = [False] * (N + 1)
dp = [[0] * (N + 1) for _ in range(len(S) + 1)]
result = 0


def dfs(parent, path):
    global result
    visited[parent] = True
    flag = False
    if len(path) != 0:
        for i in range(1, len(S) + 1):
            if path[-1] == S[i - 1]:
                dp[i][len(path)] = dp[i - 1][len(path) - 1] + 1
            else:
                dp[i][len(path)] = max(dp[i - 1][len(path)], dp[i][len(path) - 1])

    for conn in connections[parent]:
        if not visited[conn[0]]:
            flag = True
            dfs(conn[0], path + conn[1])
    if not flag:
        result = max(result, dp[len(S)][len(path)])


dfs(1, "")


print(result)
