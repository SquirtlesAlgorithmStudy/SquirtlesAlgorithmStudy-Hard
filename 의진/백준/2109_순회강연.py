import sys
import heapq
from collections import defaultdict

input = sys.stdin.readline


def main():
    N = int(input())
    if N == 0:
        return 0
    data = [tuple(map(int, input().split())) for _ in range(N)]

    data_dict = defaultdict(list)

    for item in data:
        data_dict[item[1]].append(item[0])

    day = max(data, key=lambda x: x[1])[1]
    pq = []

    ans = 0

    while day > 0:
        if data_dict[day]:
            for item in data_dict[day]:
                heapq.heappush(pq, -item)

        if pq:
            ans -= heapq.heappop(pq)

        day -= 1

    return ans


print(main())
