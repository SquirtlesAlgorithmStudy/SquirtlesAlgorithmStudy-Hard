def rotate(query, board):
    s_row = query[0]
    s_col = query[1]
    e_row = query[2]
    e_col = query[3]

    now_r = s_row
    now_c = s_col

    temp = board[now_r][now_c]
    min_val = float("inf")
    for _ in range(e_col - s_col):
        now_c += 1
        min_val = min(min_val, temp)
        board[now_r][now_c], temp = temp, board[now_r][now_c]
    for _ in range(e_row - s_row):
        now_r += 1
        min_val = min(min_val, temp)
        board[now_r][now_c], temp = temp, board[now_r][now_c]
    for _ in range(e_col - s_col):
        now_c -= 1
        min_val = min(min_val, temp)
        board[now_r][now_c], temp = temp, board[now_r][now_c]
    for _ in range(e_row - s_row):
        now_r -= 1
        min_val = min(min_val, temp)
        board[now_r][now_c], temp = temp, board[now_r][now_c]

    return min_val


def solution(rows, columns, queries):
    board = [[0] * (columns + 1) for _ in range(rows + 1)]
    cnt = 1
    for r in range(1, rows + 1):
        for c in range(1, columns + 1):
            board[r][c] = cnt
            cnt += 1

    answer = []
    for query in queries:
        answer.append(rotate(query, board))

    return answer
