from collections import deque
import sys

input = sys.stdin.readline

R, C = map(int, input().split())
board = [list(input().rstrip()) for _ in range(R)]
dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


def bfs_sonagi(start_r, start_c):
    queue = deque()
    dist = 0
    queue.append((start_r, start_c, dist))
    board[start_r][start_c] = dist

    while queue:
        r, c, dist = queue.popleft()

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= R or nc < 0 or nc >= C:
                continue

            if board[nr][nc] == "X" or board[nr][nc] == "H":
                continue

            if isinstance(board[nr][nc], int) and board[nr][nc] <= dist + 1:
                continue

            board[nr][nc] = dist + 1
            queue.append((nr, nc, dist + 1))


def bfs_car(start_r, start_c):
    global h_coord
    queue = deque()
    visited = [[False] * C for _ in range(R)]
    dist = 0
    queue.append((start_r, start_c, dist))
    board[start_r][start_c] = dist
    visited[start_r][start_c] == True

    while queue:
        r, c, dist = queue.popleft()

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr == h_coord[0] and nc == h_coord[1]:
                return dist + 1

            if nr < 0 or nr >= R or nc < 0 or nc >= C:
                continue

            if board[nr][nc] == "X":
                continue

            if isinstance(board[nr][nc], int) and board[nr][nc] <= dist + 1:
                continue

            if visited[nr][nc]:
                continue

            visited[nr][nc] = True
            queue.append((nr, nc, dist + 1))

    return -1


s_coord_list = []
for r in range(R):
    for c in range(C):
        if board[r][c] == "W":
            w_coord = (r, c)
        elif board[r][c] == "*":
            s_coord_list.append((r, c))
        elif board[r][c] == "H":
            h_coord = (r, c)

for s_coord in s_coord_list:
    bfs_sonagi(*s_coord)

result = bfs_car(*w_coord)
if result == -1:
    print("FAIL")
else:
    print(result)
