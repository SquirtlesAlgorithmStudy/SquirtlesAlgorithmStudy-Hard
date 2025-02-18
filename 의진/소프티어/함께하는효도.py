import sys
from itertools import product

input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
position = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
result = 0
dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


def dfs(state, depth):
    global result
    if depth == 3:
        result = max(result, state["result"])
    else:
        for new_state in get_new_state_pos(state):
            new_state["result"] = state["result"]
            cache = {}
            for i in range(M):
                pos = new_state[i]
                new_state["result"] += board[pos[0]][pos[1]]
                cache[i] = board[pos[0]][pos[1]]
                board[pos[0]][pos[1]] = 0
            dfs(new_state, depth + 1)
            for i in range(M):
                pos = new_state[i]
                board[pos[0]][pos[1]] = cache[i]


def get_new_state_pos(state):
    candidates = []
    for i in range(M):
        candidates.append([])
        r, c = state[i][0], state[i][1]
        for j in range(4):
            nr = r + dr[j]
            nc = c + dc[j]
            if nr < 0 or nr >= N or nc < 0 or nc >= N:
                continue

            candidates[-1].append((nr, nc))

    for item in product(*candidates):
        if len(item) != len(set(item)):
            continue
        yield {i: value for i, value in enumerate(item)}


init_state = {"result": 0}
for idx, pos in enumerate(position):
    init_state[idx] = pos
    init_state["result"] += board[pos[0]][pos[1]]
    board[pos[0]][pos[1]] = 0

dfs(init_state, 0)
print(result)
