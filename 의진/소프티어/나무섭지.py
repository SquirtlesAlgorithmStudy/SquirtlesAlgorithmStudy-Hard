import sys
from collections import deque

input = sys.stdin.readline
destination = ()
ghosts = []
start_pos = ()
INF = float("inf")


def get_info(x, r):
    global destination, ghosts, start_pos
    for c, char in enumerate(x):
        if char == "D":
            destination = (r, c)
        elif char == "G":
            ghosts.append((r, c))
        elif char == "N":
            start_pos = (r, c)
    return x


n, m = map(int, input().split())
board = [list(get_info(input().strip(), r)) for r in range(n)]
dist = [[[INF, False] for _ in range(m)] for _ in range(n)]
dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


def ghost_scan(ghosts):
    queue = deque()
    for start_r, start_c in ghosts:
        queue.append((start_r, start_c, 0))
        dist[start_r][start_c][0] = 0

    while queue:
        r, c, d = queue.popleft()

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= n or nc < 0 or nc >= m:
                continue
            if dist[nr][nc][0] != INF:
                continue

            queue.append((nr, nc, d + 1))
            dist[nr][nc][0] = d + 1


def nam_woo_move(start_r, start_c):
    queue = deque()
    queue.append((start_r, start_c, 0))
    dist[start_r][start_c][1]

    while queue:
        r, c, d = queue.popleft()
        if d == dist[destination[0]][destination[1]][0]:
            return False

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= n or nc < 0 or nc >= m:
                continue
            if board[nr][nc] == "#":
                continue
            if dist[nr][nc][1]:
                continue
            if dist[nr][nc][0] <= d + 1:
                continue
            if (nr, nc) == destination:
                return True

            queue.append((nr, nc, d + 1))
            dist[nr][nc][1] = True

    return False


ghost_scan(ghosts)


print("Yes" if nam_woo_move(start_pos[0], start_pos[1]) else "No")
