import heapq


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        pq = []
        heapq.heappush(pq, 1)
        is_registered = set()
        is_registered.add(1)

        for _ in range(n - 1):
            min_val = heapq.heappop(pq)
            for m in [2, 3, 5]:
                if m * min_val not in is_registered:
                    heapq.heappush(pq, m * min_val)
                    is_registered.add(m * min_val)
        return heapq.heappop(pq)
