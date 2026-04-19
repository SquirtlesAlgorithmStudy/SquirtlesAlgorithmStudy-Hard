input = open(0).readline
def solve():
    N, X = map(int, input().split())
    bp = [0] * N
    p = [0] * N
    bp[0] = 1
    p[0] = 1
    for i in range(1, N):
        bp[i] = bp[i - 1] * 2 + 3
        p[i] = p[i - 1] * 2 + 1
    ans = 0
    N -= 1
    while N >= 0:
        if X <= 1:
            return ans
        elif 1 < X < bp[N] + 1:
            X -= 1
            N -= 1
        elif X == bp[N] + 1:
            return ans + p[N]
        elif X == bp[N] + 2:
            return ans + p[N] + 1
        elif bp[N] + 2 < X < 2 * bp[N] + 2:
            ans += p[N] + 1
            X -= bp[N] + 2
            N -= 1
        else:
            return ans + 2 * p[N] + 1
    return ans
print(solve())
