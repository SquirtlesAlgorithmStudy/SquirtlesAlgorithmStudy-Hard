import math
import sys


def query(seller, amount, name_2_idx, answer, referral):
    target_idx = name_2_idx[seller]
    upper_profit = math.floor(0.1 * amount)
    my_profit = amount - upper_profit
    answer[target_idx] += my_profit
    ref = referral[target_idx]
    if ref != "-" and upper_profit != 0:
        query(ref, upper_profit, name_2_idx, answer, referral)


def solution(enroll, referral, seller, amount):
    sys.setrecursionlimit(10**9)
    answer = [0] * len(enroll)
    name_2_idx = {}
    for i, e in enumerate(enroll):
        name_2_idx[e] = i

    for s, a in zip(seller, amount):
        query(s, 100 * a, name_2_idx, answer, referral)

    return answer
