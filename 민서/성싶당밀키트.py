input = open(0).readline
N, G, K = map(int, input().split())
oS = []
xS = []
oL = []
xL = []
for _ in range(N):
    s, l, o = map(int, input().split())
    if o:
        xS.append(s)
        xL.append(l)
    else:
        oS.append(s)
        oL.append(l)
K = max(0, N - K - len(oS))
def getG(day):
    G = sum(s * max(1, day - l) for s, l in zip(oS, oL))
    arr = sorted(s * max(1, day - l) for s, l in zip(xS, xL))
    G += sum(arr[:K])
    return G
lo, hi = 0, 1<<31
while lo < hi:
    mid = (lo + hi) // 2
    if getG(mid) > G:
        hi = mid
    else:
        lo = mid + 1
print(lo - 1)
