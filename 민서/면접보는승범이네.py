import io, os
import heapq as hq
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
INF = 1<<40
def main():
    N, M, K = map(int, input().split())
    graph = [{} for _ in range(N + 1)]
    dist = [INF] * (N + 1)
    for _ in range(M):
        u, v, c = map(int, input().split())
        if c0:=(graph[v].get(u)) is not None and c0 <= c:
            continue
        graph[v][u] = c
    marked = [*map(int, input().split())]
    que = []
    for m in marked:
        dist[m] = 0
        que.append((0, m))
    ans = 0
    while que:
        d, u = hq.heappop(que)
        if d > dist[u]:
            continue
        ans = d
        for v, w in graph[u].items():
            if d + w < dist[v]:
                dist[v] = d + w
                hq.heappush(que, (d + w, v))
    for i, d in enumerate(dist):
        if d == ans:
            print(i)
            print(ans)
            return
main()
