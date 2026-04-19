import heapq as hq
input = open(0).readline
INF = 1<<30
def main():
    x1, y1, x2, y2 = map(int, input().split())
    X = [x1, x2]
    Y = [y1, y2]
    N = int(input())
    for _ in range(N):
        x, y = map(int, input().split())
        X.append(x)
        Y.append(y)
    N += 2
    is_prime = [True] * 10000
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, 101):
        if is_prime[i]:
            for j in range(i * i, 10000, i):
                is_prime[j] = False
    graph = [[] for _ in range(N)]
    for i in range(N):
        for j in range(i + 1, N):
            d = int(((X[i] - X[j]) ** 2 + (Y[i] - Y[j]) ** 2) ** 0.5)
            if is_prime[d]:
                graph[i].append((j, d))
                graph[j].append((i, d))
    dist = [INF] * N
    que = [(0, 0)]
    while que:
        d, u = hq.heappop(que)
        if d > dist[u]:
            continue
        if u == 1:
            print(d)
            return
        for v, w in graph[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                hq.heappush(que, (d + w, v))
    print(-1)
main()
