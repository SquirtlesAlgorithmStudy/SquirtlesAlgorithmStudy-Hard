import sys
import heapq

input = sys.stdin.readline


def main():
    N, K = map(int, input().split())
    members = list(map(int, input().split()))

    pq = []

    if N == K:
        return 0

    for i in range(len(members) - 1):
        heapq.heappush(pq, -members[i + 1] + members[i])

    ans = members[-1] - members[0]

    for k in range(K - 1):
        ans += heapq.heappop(pq)

    return ans


print(main())
