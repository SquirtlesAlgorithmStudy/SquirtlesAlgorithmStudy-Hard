import sys
import heapq as hq
input = open(0).readline
def main():
    N, K = map(int, input().split())
    A = [*map(int, input().split())]
    B = [*map(int, input().split())]
    buckets = [[] for _ in range(N + 1)]
    bucket_idxs = [*set(A)]
    for a, b in zip(A, B):
        hq.heappush(buckets[a], b)
    result = []
    total = 0
    size = 0
    ans = []
    for _ in range(N):
        nbucket_idxs = []
        for i in bucket_idxs:
            n = hq.heappop(buckets[i])
            if len(buckets[i]) > 0:
                nbucket_idxs.append(i)
            if size < K:
                hq.heappush(result, -n)
                total += n
                size += 1
            elif n < -result[0]:
                hq.heappush(result, -n)
                total += n
                total += hq.heappop(result)
        bucket_idxs = nbucket_idxs
        if size < K:
            ans.append("-1")
        else:
            ans.append(str(total))
    sys.stdout.write(" ".join(ans))
main()
