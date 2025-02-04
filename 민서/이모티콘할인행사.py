from itertools import product
def get_ans(users, emoticons, rates):
    n_user, total = 0, 0
    for r_th, v_th in users:
        value = 0
        for e, r in zip(emoticons, rates):
            if r >= r_th:
                value += e - e // 100 * r
        if value >= v_th:
            n_user += 1
        else:
            total += value
    return n_user, total

def solution(users, emoticons):
    n_user, total = 0, 0
    for rates in product([10, 20, 30, 40], repeat=len(emoticons)):
        a, b = get_ans(users, emoticons, rates)
        if a > n_user:
            n_user, total = a, b
        elif a == n_user and b > total:
            n_user, total = a, b
    return [n_user, total]
