input = open(0).readline
N, A, B = map(int, input().split())
que_A = set([A])
que_B = [B]
ans = None
depth = 0
while que_A and que_B and ans is None:
    nque_A, nque_B = set(), []
    for a in que_A:
        for way in [-1, 1]:
            na = a + way * (1<<depth)
            if not 0 < na <= N:
                continue
            nque_A.add(na)
    for b in que_B:
        for way in [-1, 1]:
            nb = b + way * (1<<depth)
            if not 0 < nb <= N:
                continue
            if nb in nque_A:
                ans = depth + 1
            nque_B.append(nb)
    que_A, que_B = nque_A, nque_B
    depth += 1
if ans is None:
    print(-1)
else:
    print(ans)
