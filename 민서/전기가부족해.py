import heapq as hq
input = open(0).readline
def main():
    N, M, K = map(int, input().split())
    marked = [*map(int, input().split())]
    edges = []
    for _ in range(M):
        u, v, w = map(int, input().split())
        hq.heappush(edges, (w, u, v))
    parent = [-1] * (N + 1)
    def find(x):
        if parent[x] < 0:
            return x
        parent[x] = find(parent[x])
        return parent[x]
    def union(x, y):
        x, y = find(x), find(y)
        if x == y:
            return False
        if x < y:
            parent[y] = x
        else:
            parent[x] = y
        return True
    for m in marked:
        union(0, m)
    cnt = K
    ans = 0
    while edges and cnt < N:
        w, u, v = hq.heappop(edges)
        if union(u, v):
            ans += w
            cnt += 1
    print(ans)
main()
