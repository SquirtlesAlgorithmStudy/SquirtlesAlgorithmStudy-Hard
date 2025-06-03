input = open(0).readline
N = int(input())
A = [*map(int, input().split())]
l, r = 0, N - 1
mn = 1<<30
while l < r:
    s = A[l] + A[r]
    if abs(s) < mn:
        mn = abs(s)
        ans = s
    if s < 0:
        l += 1
    elif s > 0:
        r -= 1
    else:
        break
print(ans)
