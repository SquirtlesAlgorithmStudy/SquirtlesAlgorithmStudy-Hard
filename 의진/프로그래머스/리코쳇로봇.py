from collections import deque


def bfs(start, board, visited):
    queue = deque()
    queue.append((start[0], start[1], 0))
    visited[start[0]][start[1]] = 1

    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]

    while queue:
        r, c, dist = queue.popleft()
        for i in range(4):
            nr = r
            nc = c
            while True:
                if i in [0, 1]:
                    if (
                        nr + dr[i] < 0
                        or nr + dr[i] >= len(board)
                        or board[nr + dr[i]][c] == "D"
                    ):
                        break
                    else:
                        nr = nr + dr[i]
                elif i in [2, 3]:
                    if (
                        nc + dc[i] < 0
                        or nc + dc[i] >= len(board[0])
                        or board[r][nc + dc[i]] == "D"
                    ):
                        break
                    else:
                        nc = nc + dc[i]

            if visited[nr][nc] == 1:
                continue

            if board[nr][nc] == "G":
                return dist + 1

            queue.append((nr, nc, dist + 1))
            visited[nr][nc] = 1

    return -1


def solution(board):
    for r in range(len(board)):
        for c in range(len(board[0])):
            if board[r][c] == "R":
                start = (r, c)
                break

    visited = [[0] * len(board[0]) for _ in range(len(board))]
    answer = bfs(start, board, visited)
    return answer
