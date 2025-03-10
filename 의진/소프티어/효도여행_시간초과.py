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


def get_all_strings(connections):
    visited = [False] * (N + 1)
    path_list = []

    def dfs(parent, path):
        visited[parent] = True
        flag = False
        for conn in connections[parent]:
            if not visited[conn[0]]:
                flag = True
                dfs(conn[0], path + conn[1])
        if not flag:
            path_list.append(path)

    dfs(1, "")

    return path_list


def get_lcs_len(S, T):
    dp = [[0] * (len(T) + 1) for _ in range(len(S) + 1)]
    for i in range(len(S) + 1):
        for j in range(len(T) + 1):
            if i == 0 or j == 0:
                continue
            elif S[i - 1] == T[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[-1][-1]


all_strings = get_all_strings(connections)  # O(N)
result = 0

for T in all_strings:  # O(ST^2)
    if result > len(T):
        continue
    result = max(result, get_lcs_len(S, T))

print(result)
