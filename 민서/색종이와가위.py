def main():
    n, k = map(int, input().split())
    lo, hi = 0, n // 2
    while lo <= hi:
        mid = (lo + hi) // 2
        x = (mid + 1) * (n - mid + 1)
        if x == k:
            print("YES")
            return
        if x < k:
            lo = mid + 1
        else:
            hi = mid - 1
    print("NO")
main()
