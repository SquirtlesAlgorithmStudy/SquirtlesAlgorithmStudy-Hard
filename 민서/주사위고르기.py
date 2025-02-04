from itertools import combinations, product
def calc_win_rate(A, B):
    A_cases = sorted(map(sum, product(*A)))
    B_cases = sorted(map(sum, product(*B)))
    n_case = len(A_cases)
    cnt = 0
    j = 0
    for a in A_cases:
        while j < n_case and B_cases[j] < a:
            j += 1
        cnt += j
    return cnt / (n_case * n_case)

def solution(dice):
    n = len(dice)
    answer = []
    win_rate = 0
    for a in combinations(range(1, n + 1), n // 2):
        b = [x for x in range(1, n + 1) if x not in a]
        A, B = [dice[i - 1] for i in a], [dice[j - 1] for j in b]
        new_win_rate = calc_win_rate(A, B)
        if new_win_rate > win_rate:
            win_rate = new_win_rate
            answer = a
    return answer
