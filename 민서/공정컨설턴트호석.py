import heapq as hq
input = open(0).readline
def able(arr, K, X):
    que = [0] * K
    for n in arr:
        tmp = hq.heappop(que)
        if tmp + n > X:
            return False
        hq.heappush(que, tmp + n)
    return True
def main():
    N, X = map(int, input().split())
    arr = [*map(int, input().split())]
    lo, hi = 1, N
    while lo <= hi:
        mid = (lo + hi) // 2
        if able(arr, mid, X):
            hi = mid - 1
        else:
            lo = mid + 1
    print(lo)
main()
