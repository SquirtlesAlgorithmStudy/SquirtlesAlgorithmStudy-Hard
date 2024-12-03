from pprint import pprint


def get_diff_board(board):
    col_diff_board = [[0] * (len(board[0]) + 1) for _ in range(len(board) + 1)]
    for r in range(len(board)):
        for c in range(len(board[0])):
            if c == 0:
                col_diff_board[r][c] = board[r][c]
            else:
                col_diff_board[r][c] = board[r][c] - board[r][c - 1]

    diff_board = [[0] * (len(board[0]) + 1) for _ in range(len(board) + 1)]

    for r in range(len(board)):
        for c in range(len(board[0])):
            if r == 0:
                diff_board[r][c] = col_diff_board[r][c]
            else:
                diff_board[r][c] = col_diff_board[r][c] - col_diff_board[r - 1][c]

    return diff_board


def apply_skill(skill, diff_board):
    if skill[0] == 1:
        operand = -skill[5]
    else:
        operand = skill[5]

    r1 = skill[1]
    c1 = skill[2]
    r2 = skill[3]
    c2 = skill[4]

    diff_board[r1][c1] += operand
    diff_board[r2 + 1][c1] -= operand
    diff_board[r1][c2 + 1] -= operand
    diff_board[r2 + 1][c2 + 1] += operand


def get_answer(diff_board, board):
    col_diff_board = [[0] * len(board[0]) for _ in range(len(board))]
    for c in range(len(board[0])):
        for r in range(len(board)):
            if r == 0:
                col_diff_board[r][c] = diff_board[r][c]
            else:
                col_diff_board[r][c] = col_diff_board[r - 1][c] + diff_board[r][c]

    answer = 0
    new_board = [[0] * len(board[0]) for _ in range(len(board))]
    for r in range(len(board)):
        for c in range(len(board[0])):
            if c == 0:
                new_board[r][c] = col_diff_board[r][c]
            else:
                new_board[r][c] = new_board[r][c - 1] + col_diff_board[r][c]
            if new_board[r][c] > 0:
                answer += 1

    # pprint(new_board)

    return answer


def solution(board, skill):
    diff_board = get_diff_board(board)
    # pprint(diff_board)
    for s in skill:
        apply_skill(s, diff_board)

    return get_answer(diff_board, board)
