import sys
import heapq

input = sys.stdin.readline

N = int(input())
mos = [tuple(map(int, input().split())) for _ in range(N)]

events = []
prefix_sum = [(0, -1)]

for m in mos:
    heapq.heappush(events, (m[0], 1))
    heapq.heappush(events, (m[1], -1))

buffer = 0
while events:
    event = heapq.heappop(events)
    buffer += event[1]

    if not events or events[0][0] != event[0]:
        prefix_sum.append((prefix_sum[-1][0] + buffer, event[0]))
        buffer = 0

max_val = max(prefix_sum)[0]
print(max_val)

start_flag = False
for p in prefix_sum:
    if not start_flag and p[0] == max_val:
        start_flag = True
        start = p[1]
    if start_flag and p[0] != max_val:
        end = p[1]
        break
print(start, end)
