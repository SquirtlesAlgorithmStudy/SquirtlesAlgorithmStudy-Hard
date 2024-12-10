import sys

sys.setrecursionlimit(100_000_000)


def travel(r, c, i, grid, state, depth):
    grid_dr = [0, 0, 1, 0]
    grid_dc = [1, 0, 0, 0]
    state[r][c][i] = 1

    direction = grid[(r + grid_dr[i]) % len(grid)][(c + grid_dc[i]) % len(grid[0])]

    if direction == "S":
        if i == 0:
            next_state = (r, (c + 1) % len(grid[0]), 0)
        elif i == 1:
            next_state = (r, (c - 1) % len(grid[0]), 1)
        elif i == 2:
            next_state = ((r + 1) % len(grid), c, 2)
        elif i == 3:
            next_state = ((r - 1) % len(grid), c, 3)

    elif direction == "L":
        if i == 0:
            next_state = ((r - 1) % len(grid), (c + 1) % len(grid[0]), 3)
        elif i == 1:
            next_state = (r, c, 2)
        elif i == 2:
            next_state = ((r + 1) % len(grid), c, 0)
        elif i == 3:
            next_state = (r, (c - 1) % len(grid[0]), 1)

    elif direction == "R":
        if i == 0:
            next_state = (r, (c + 1) % len(grid[0]), 2)
        elif i == 1:
            next_state = ((r - 1) % len(grid), c, 3)
        elif i == 2:
            next_state = ((r + 1) % len(grid), (c - 1) % len(grid[0]), 1)
        elif i == 3:
            next_state = (r, c, 0)

    if state[next_state[0]][next_state[1]][next_state[2]] == 1:
        return depth
    else:
        return travel(
            next_state[0], next_state[1], next_state[2], grid, state, depth + 1
        )


def solution(grid):
    state = [[[0] * 4 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    answer = []

    for r in range(len(grid)):
        for c in range(len(grid[0])):
            for i in range(4):
                if state[r][c][i] == 0:
                    answer.append(travel(r, c, i, grid, state, 1))

    answer.sort()
    return answer
