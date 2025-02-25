input = open(0).readline
n, m = map(int, input().split())
parse = {".": 0, "#": 1, "N": 0, "D": 0, "G": 1}
arr = [[] for _ in range(n)]
G = []
for i in range(n):
    for j, c in enumerate(input().rstrip()):
        arr[i].append(parse[c])
        if c == "N":
            N = (i, j)
        elif c == "D":
            D = (i, j)
        elif c == "G":
            G.append((i, j))
INF = 1 << 30
ghost_time = min(abs(gi - D[0]) + abs(gj - D[1]) for gi, gj in G) if G else INF
namu_time = INF
di = [1, -1, 0, 0]
dj = [0, 0, 1, -1]
que = [(N[0], N[1], 0)]
while que and namu_time == INF:
    nque = []
    for i, j, t in que:
        for k in range(4):
            ni, nj = i + di[k], j + dj[k]
            if not (0 <= ni < n and 0 <= nj < m) or arr[ni][nj]:
                continue
            if ni == D[0] and nj == D[1]:
                namu_time = t + 1
            nque.append((ni, nj, t + 1))
            arr[ni][nj] = 1
    que = nque
if namu_time < ghost_time:
    print("Yes")
else:
    print("No")
