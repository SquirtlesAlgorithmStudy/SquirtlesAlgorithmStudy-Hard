input = open(0).readline
R, C = map(int, input().split())
mapping = {".": 0, "X": -1, "H": -2, "W": 0, "*": 0}
arr = [[] for _ in range(R)]
INF = 1<<30
rain_time = [[INF] * C for _ in range(R)]
que = []
for i in range(R):
    for j, c in enumerate(input().rstrip()):
        arr[i].append(mapping[c])
        if c == "W":
            human = (i, j)
        elif c == "*":
            que.append((0, i, j))
            rain_time[i][j] = 0
di = [-1, 1, 0, 0]
dj = [0, 0, -1, 1]
while que:
    nque = []
    for t, i, j in que:
        for n in range(4):
            ni, nj = i + di[n], j + dj[n]
            if not (0 <= ni < R and 0 <= nj < C):
                continue
            if arr[ni][nj] != 0 or rain_time[ni][nj] < INF:
                continue
            rain_time[ni][nj] = t + 1
            nque.append((t + 1, ni, nj))
    que = nque
ans = -1
que = [(0, *human)]
while que and ans == -1:
    nque = []
    for t, i, j in que:
        if ans != -1:
            break
        for n in range(4):
            ni, nj = i + di[n], j + dj[n]
            if not (0 <= ni < R and 0 <= nj < C):
                continue
            if arr[ni][nj] == -2:
                ans = t + 1
            if arr[ni][nj] != 0 or rain_time[ni][nj] <= t + 1:
                continue
            arr[ni][nj] = t + 1
            nque.append((t + 1, ni, nj))
    que = nque
if ans == -1:
    print("FAIL")
else:
    print(ans)
