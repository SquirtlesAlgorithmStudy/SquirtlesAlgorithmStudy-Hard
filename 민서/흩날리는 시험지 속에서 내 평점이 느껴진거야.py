input = open(0).readline
N, K = map(int, input().split())
arr = [*map(int, input().split())]
lo, hi = 0, 2000000
while lo < hi:
    mid = (lo + hi) // 2
    s = 0
    cnt = 0
    for n in arr:
        if s + n < mid:
            s += n
        else:
            cnt += 1
            s = 0
    if cnt < K:
        hi = mid
    else:
        lo = mid + 1
print(lo - 1)
