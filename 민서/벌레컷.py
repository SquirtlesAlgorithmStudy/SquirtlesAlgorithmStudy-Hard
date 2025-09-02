input = open(0).readline
def main():
    N = int(input())
    A = [*map(int, input().split())]
    acc = [0]
    for n in A:
        acc.append(acc[-1] + n)
    x, y = 1, N - 1
    ans = 0
    while acc[y] - acc[x] > acc[N] - acc[y]:
        if acc[x] >= acc[N] - acc[y]:
            y -= 1
            continue
        lo, hi = x, y
        while lo <= hi:
            mid = (lo + hi) // 2
            if acc[mid] - acc[x] > acc[N] - acc[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        ans += y - hi
        x += 1
    print(ans)
main()
