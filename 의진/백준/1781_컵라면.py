import sys
import heapq

input = sys.stdin.readline

N = int(input())
problems = [tuple(map(int, input().split())) for _ in range(N)]
deadline_list = [[] for _ in range(N + 1)]

for problem in problems:
    deadline_list[problem[0]].append(problem[1])

pq = []
ans = 0
for deadline in range(N, 0, -1):
    for item in deadline_list[deadline]:
        heapq.heappush(pq, -item)
    if pq:
        solving = -heapq.heappop(pq)
        ans += solving

print(ans)
