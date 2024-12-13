def check_pass(th, stones, k):
    cnt = 0
    for s in stones:
        if s - th < 0:
            cnt += 1
        else:
            cnt = 0
        if cnt >= k:
            return False
    return True

def solution(stones, k):
    lo, hi = 0, 200_000_000
    while lo < hi:
        mid = (lo + hi) // 2
        if check_pass(mid, stones[:], k):
            lo = mid + 1
        else:
            hi = mid
    return lo - 1
