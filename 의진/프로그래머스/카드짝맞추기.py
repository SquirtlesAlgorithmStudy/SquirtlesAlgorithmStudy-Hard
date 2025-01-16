from itertools import permutations
import copy
import sys


def get_dist(start, end, board):
    s_row = start[0]
    s_col = start[1]
    e_row = end[0]
    e_col = end[1]

    # row 방향 이동 후 col 이동
    dist = 0
    if s_row < e_row:
        cnt = 0
        for i in range(s_row + 1, e_row + 1):
            if board[i][s_col] != 0 or i + 1 == 4:
                cnt += 1
        if cnt == 0:
            dist += e_row - s_row
        else:
            dist += cnt

    elif s_row > e_row:
        cnt = 0
        for i in range(s_row - 1, e_row - 1, -1):
            if board[i][s_col] != 0 or i - 1 == -1:
                cnt += 1
        if cnt == 0:
            dist += s_row - e_row
        else:
            dist += cnt

    if s_col < e_col:
        cnt = 0
        for i in range(s_col + 1, e_col + 1):
            if board[e_row][i] != 0 or i + 1 == 4:
                cnt += 1
        if cnt == 0:
            dist += e_col - s_col
        else:
            dist += cnt

    elif s_col > e_col:
        cnt = 0
        for i in range(s_col - 1, e_col - 1, -1):
            if board[e_row][i] != 0 or i - 1 == -1:
                cnt += 1
        if cnt == 0:
            dist += s_col - e_col
        else:
            dist += cnt

    ans_dist = dist
    dist = 0

    # col 이동 후 row 이동
    if s_col < e_col:
        cnt = 0
        for i in range(s_col + 1, e_col + 1):
            if board[s_row][i] != 0 or i + 1 == 4:
                cnt += 1
        if cnt == 0:
            dist += e_col - s_col
        else:
            dist += cnt

    elif s_col > e_col:
        cnt = 0
        for i in range(s_col - 1, e_col - 1, -1):
            if board[s_row][i] != 0 or i - 1 == -1:
                cnt += 1
        if cnt == 0:
            dist += s_col - e_col
        else:
            dist += cnt

    if s_row < e_row:
        cnt = 0
        for i in range(s_row + 1, e_row + 1):
            if board[i][e_col] != 0 or i + 1 == 4:
                cnt += 1
        if cnt == 0:
            dist += e_row - s_row
        else:
            dist += cnt

    elif s_row > e_row:
        cnt = 0
        for i in range(s_row - 1, e_row - 1, -1):
            if board[i][e_col] != 0 or i - 1 == -1:
                cnt += 1
        if cnt == 0:
            dist += s_row - e_row
        else:
            dist += cnt

    ans_dist = min(dist, ans_dist)
    return ans_dist


def dfs(cr, cc, case, dist, board, card_pos):
    if case is None:
        return dist
    else:
        dest = case[0]
        first_pos = card_pos[dest][0]
        second_pos = card_pos[dest][1]
        if len(case) == 1:
            case = None
        else:
            case = case[1:]

        d_11 = get_dist((cr, cc), first_pos, board)
        d_12 = get_dist(first_pos, second_pos, board)
        d_21 = get_dist((cr, cc), second_pos, board)
        d_22 = get_dist(second_pos, first_pos, board)

        board[first_pos[0]][first_pos[1]] = 0
        board[second_pos[0]][second_pos[1]] = 0

        d_1 = dfs(
            second_pos[0], second_pos[1], case, dist + d_11 + d_12, board, card_pos
        )
        d_2 = dfs(first_pos[0], first_pos[1], case, dist + d_21 + d_22, board, card_pos)

        board[first_pos[0]][first_pos[1]] = dest
        board[second_pos[0]][second_pos[1]] = dest

        return min(d_1, d_2)


def solution(board, r, c):
    sys.setrecursionlimit(10**7)
    card_pos = {i: [] for i in range(1, 9)}
    card_set = set()
    for row in range(4):
        for col in range(4):
            if board[row][col] != 0:
                card_pos[board[row][col]].append((row, col))
                card_set.add(board[row][col])

    # return 1

    answer = float("inf")

    for case in permutations(list(card_set), len(card_set)):
        answer = min(answer, dfs(r, c, case, 0, board, card_pos))
    answer += 2 * len(card_set)

    return answer
