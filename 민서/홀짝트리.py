import sys;sys.setrecursionlimit(1<<30)
def solution(nodes, edges):
    answer = [0, 0]
    N = len(nodes)
    node2i = {n: i for i, n in enumerate(nodes)}
    graph = [[] for _ in range(N)]
    for a, b in edges:
        graph[node2i[a]].append(node2i[b])
        graph[node2i[b]].append(node2i[a])
    total = []
    cnt = []
    visited = [False] * N
    def dfs(n):
        visited[n] = True
        total[-1] += 1
        if nodes[n] % 2 == len(graph[n]) % 2:
            cnt[-1] += 1
        for c in graph[n]:
            if not visited[c]:
                dfs(c)
    for i in range(N):
        if visited[i]:
            continue
        total.append(0)
        cnt.append(0)
        dfs(i)
    for i in range(len(total)):
        if cnt[i] == 1:
            answer[0] += 1
        if total[i] - cnt[i] == 1:
            answer[1] += 1
    return answer
