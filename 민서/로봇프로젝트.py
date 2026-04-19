import io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def solve(X, N, L):
    lo, hi = 0, N - 1
    while lo < hi:
        s = L[lo] + L[hi]
        if s == X:
            print("yes", L[lo], L[hi])
            return
        elif s < X:
            lo += 1
        else:
            hi -= 1
    print("danger")
while True:
    ln = input()
    if not ln:
        break
    X = int(ln)
    N = int(input())
    L = [int(input()) for _ in range(N)]
    solve(X * 10000000, N, sorted(L))
