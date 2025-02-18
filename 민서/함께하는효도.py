import itertools
import sys
sys.setrecursionlimit(1<<30)
input = open(0).readline
N, M = map(int, input().split())
arr = [[*map(int, input().split())] for _ in range(N)]
xy = [[int(n) - 1 for n in input().split()] for _ in range(M)]
visited = [0] * (N * N)
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
ans = []
def dfs(xys, visited, depth, score):
    check = []
    for x, y in xys:
        if not visited[x*N + y]:
            check.append((x, y))
            score += arr[x][y]
            visited[x*N + y] = 1
    if depth == 3:
        ans.append(score)
        return
    case = []
    for x, y in xys:
        nxy = []
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and (nx, ny) not in nxy:
                nxy.append((nx, ny))
        case.append(nxy)
    for nxys in itertools.product(*case):
        dfs(nxys, visited[:], depth + 1, score)
dfs(xy, visited, 0, 0)
print(max(ans))
