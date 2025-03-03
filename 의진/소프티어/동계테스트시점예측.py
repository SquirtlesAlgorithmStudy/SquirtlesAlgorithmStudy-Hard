import sys
from collections import deque

input = sys.stdin.readline

R, C = map(int, input().split())
ice_dict = {}
dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


def preprocess(x, r):
    sp = x.split()
    ret = []
    for c, char in enumerate(sp):
        if char == "1":
            ice_dict[(r, c)] = 1
        ret.append(int(char))
    return ret


board = [preprocess(input(), r) for r in range(R)]


def air_scan(board):
    visited = [[0] * C for _ in range(R)]

    def bfs(start, visited, group_label):
        this_group_is_in = True
        queue = deque()
        queue.append((start[0], start[1]))
        visited[start[0]][start[1]] = group_label

        while queue:
            r, c = queue.popleft()

            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]

                if nr < 0 or nr >= R or nc < 0 or nc >= C:
                    this_group_is_in = False
                    continue
                if visited[nr][nc] != 0:
                    continue

                if board[nr][nc] == 1:
                    continue

                queue.append((nr, nc))
                visited[nr][nc] = group_label

        return this_group_is_in

    group_label = 1
    info = [False]
    for r in range(R):
        for c in range(C):
            if visited[r][c] == 0 and board[r][c] == 0:
                info.append(bfs((r, c), visited, group_label))
                group_label += 1
    for r in range(R):
        for c in range(C):
            if info[visited[r][c]]:
                board[r][c] = 2


def ice_scan(ice_dict):
    for ice in ice_dict.keys():
        cnt = 0
        for i in range(4):
            nr = ice[0] + dr[i]
            nc = ice[1] + dc[i]

            if nr < 0 or nr >= R or nc < 0 or nc >= C:
                continue

            if board[nr][nc] == 0:
                cnt += 1

            if cnt == 2:
                ice_dict[ice] = 0
                break


def ice_delete(ice_set, board):
    del_list = []
    for ice, value in ice_set.items():
        if value == 0:
            board[ice[0]][ice[1]] = 0
            del_list.append(ice)

    for d in del_list:
        del ice_dict[d]


def initialize(board):
    for r in range(R):
        for c in range(C):
            if board[r][c] == 2:
                board[r][c] = 0


result = 0
while ice_dict:
    air_scan(board)
    ice_scan(ice_dict)
    result += 1
    ice_delete(ice_dict, board)
    if ice_dict:
        initialize(board)

print(result)
