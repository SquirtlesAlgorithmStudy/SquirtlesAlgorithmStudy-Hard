input = open(0).readline
INF = 1<<30
N, M = map(int, input().split())
mapping = {".": 0, "#": 1, "O": 2, "R": 3, "B": 4}
board = [[mapping[c] for c in input().rstrip()] for _ in range(N)]
memo = [[INF] * (N * M) for _ in range(N * M)]
di = [1, 0, -1, 0]
dj = [0, 1, 0, -1]
def move(ri, rj, bi, bj, way):
    blocked_red = False
    red_finish = False
    blue_finish = False
    i, j = ri, rj
    while board[i + di[way]][j + dj[way]] == 0:
        if i + di[way] == bi and j + dj[way] == bj:
            blocked_red = True
            break
        i += di[way]
        j += dj[way]
    if board[i + di[way]][j + dj[way]] == 2:
        red_finish = True
        ri, rj = 0, 0
    elif not blocked_red:
        ri, rj = i, j
    while board[bi + di[way]][bj + dj[way]] == 0 and not (bi + di[way] == ri and bj + dj[way] == rj):
        bi += di[way]
        bj += dj[way]
    if board[bi + di[way]][bj + dj[way]] == 2:
        blue_finish = True
        bi, bj = 0, 0
    if blocked_red:
        while board[ri + di[way]][rj + dj[way]] == 0 and not (ri + di[way] == bi and rj + dj[way] == bj):
            ri += di[way]
            rj += dj[way]
        if board[ri + di[way]][rj + dj[way]] == 2:
            red_finish = True
            ri, rj = 0, 0
    return red_finish, blue_finish, ri, rj, bi, bj

for i in range(N):
    for j in range(M):
        if board[i][j] == 3:
            red = (i, j)
            board[i][j] = 0
        if board[i][j] == 4:
            blue = (i, j)
            board[i][j] = 0
memo[red[0] * M + red[1]][blue[0] * M + blue[1]] = 0
ans = INF
que = [(0, *red, *blue)]
while que and que[0][0] < 10:
    nque = []
    for t, ri, rj, bi, bj in que:
        for way in range(4):
            red_finish, blue_finish, nri, nrj, nbi, nbj = move(ri, rj, bi, bj, way)
            if t + 1 < memo[nri * M + nrj][nbi * M + nbj]:
                memo[nri * M + nrj][nbi * M + nbj] = t + 1
            else:
                continue
            if not red_finish and not blue_finish:
                nque.append((t + 1, nri, nrj, nbi, nbj))
            elif red_finish and not blue_finish:
                if t + 1 < ans:
                    ans = t + 1
    que = nque
if ans < INF:
    print(ans)
else:
    print(-1)
