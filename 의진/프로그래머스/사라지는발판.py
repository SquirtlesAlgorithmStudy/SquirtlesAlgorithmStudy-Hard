dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
INF = 2**100


def solution(board, aloc, bloc):
    return dfs(aloc[0], aloc[1], bloc[0], bloc[1], board)[1]


def is_nowhere_to_move(board, r, c):
    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]

        if 0 <= nr < len(board) and 0 <= nc < len(board[0]) and board[nr][nc]:
            return False

    return True


def dfs(r_m, c_m, r_s, c_s, board):  # row_move, row_static
    # return [can moving player win?, the number of turns]
    if is_nowhere_to_move(board, r_m, c_m):
        return (False, 0)

    if r_m == r_s and c_m == c_s:
        return (True, 1)

    min_turn = INF
    max_turn = 0
    can_win = False

    for i in range(4):
        nr = r_m + dr[i]
        nc = c_m + dc[i]

        if nr < 0 or nc < 0 or nr >= len(board) or nc >= len(board[0]):
            continue

        if not board[nr][nc]:
            continue

        board[r_m][c_m] = 0
        result = dfs(r_s, c_s, nr, nc, board)
        board[r_m][c_m] = 1

        if not result[0]:
            can_win = True
            min_turn = min(min_turn, result[1])
        elif not can_win:
            max_turn = max(max_turn, result[1])

    turn = min_turn if can_win else max_turn

    return (can_win, turn + 1)
