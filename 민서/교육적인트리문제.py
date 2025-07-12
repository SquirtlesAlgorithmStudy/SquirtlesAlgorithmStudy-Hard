input = open(0).readline
input()
input()
arr = sorted(map(int, input().split()), reverse=True)
ans = 0
for n in arr:
    ans += n
    print(ans)

#####################################################################
import heapq as hq
input = open(0).readline
N = int(input())
graph = [[] for _ in range(N + 1)]
for i, n in enumerate(map(int, input().split()), start=2):
    graph[n].append(i)
value = [0] + [*map(int, input().split())]
h = [(-value[1], 1)]
ans = 0
while h:
    v, n = hq.heappop(h)
    ans -= v
    for c in graph[n]:
        hq.heappush(h, (-value[c], c))
    print(ans)
