import sys

input = sys.stdin.readline
result = 0
current = []

F = [0] + list(map(int, input().split()))


def calculate_score(scores, win_or_draw, left, right):
    if win_or_draw == "left_win":
        scores[left][0] += 3
    elif win_or_draw == "right_win":
        scores[right][0] += 3
    else:
        scores[left][0] += 1
        scores[right][0] += 1


def is_number_1_win(case):
    scores = [[0, i] for i in range(5)]
    for c, item in zip(case, [(1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)]):
        if c == 1:
            calculate_score(scores, "left_win", item[0], item[1])
        elif c == 0:
            calculate_score(scores, "draw", item[0], item[1])
        else:
            calculate_score(scores, "right_win", item[0], item[1])
    scores.sort(key=lambda x: (-x[0], x[1]))

    for s in scores[:2]:
        if s[1] == 1:
            return True
    return False


def calculate_prob(case):
    prob = 1
    for c, item in zip(case, [(1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)]):
        total = 5 * F[item[0]] + 5 * F[item[1]]
        if c == 1:
            prob *= (4 * F[item[0]]) / total
        elif c == 0:
            prob *= (F[item[0]] + F[item[1]]) / total
        else:
            prob *= (4 * F[item[1]]) / total
    return prob


def dfs():
    global result
    if len(current) == 6:
        if is_number_1_win(current):
            result += calculate_prob(current)
        return

    else:
        for candidate in [-1, 0, 1]:
            current.append(candidate)
            dfs()
            current.pop()


dfs()
result *= 100
print(f"{round(result, 3):.3f}")
