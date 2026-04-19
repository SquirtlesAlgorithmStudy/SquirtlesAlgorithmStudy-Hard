import sys
input = open(0).readline
def bellmanFord():
    dist = [0] * (N+1)
    for _ in range(N):
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            return True
    return False
TC = int(input())
for _ in range(TC):
    N, M, W = map(int, input().split())
    edges = []
    for _ in range(M):
        S, E, T = map(int, input().split())
        edges.append((S, E, T))
        edges.append((E, S, T))
    for _ in range(W):
        S, E, T = map(int, input().split())
        edges.append((S, E, -T))
    sys.stdout.write('YES\n' if bellmanFord() else 'NO\n')
