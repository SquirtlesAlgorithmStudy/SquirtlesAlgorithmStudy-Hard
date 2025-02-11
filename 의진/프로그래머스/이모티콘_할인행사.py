from itertools import product


def simulation(users, emoticons, discounts):
    plus = 0
    sales = 0
    for user in users:
        total = 0
        for idx, item in enumerate(emoticons):
            if discounts[idx] >= user[0]:
                total += item * (1 - (discounts[idx] / 100))
            if total >= user[1]:
                break
        if total >= user[1]:
            plus += 1
        else:
            sales += total
    return plus, sales


def solution(users, emoticons):
    candidates = []
    for case in product([10, 20, 30, 40], repeat=len(emoticons)):
        candidates.append(list(simulation(users, emoticons, case)))
    candidates.sort(key=lambda x: (-x[0], -x[1]))
    answer = candidates[0]
    return answer
