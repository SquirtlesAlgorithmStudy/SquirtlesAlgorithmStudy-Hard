import sys
import heapq

input = sys.stdin.readline

n = int(input())
ho_pairs = [
    tuple(sorted(list(map(lambda x: -int(x), input().split())), reverse=True))
    for _ in range(n)
]
d = int(input())

heapq.heapify(ho_pairs)
candidate = []
answer = 0

while ho_pairs:
    pair = heapq.heappop(ho_pairs)
    heapq.heappush(candidate, pair[1])

    while True:
        if len(candidate) == 0:
            break
        if -candidate[0] > -pair[0] + d:
            heapq.heappop(candidate)
        else:
            answer = max(len(candidate), answer)
            break

print(answer)
