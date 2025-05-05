from itertools import combinations


def solution(n, q, ans):
    answer = 0
    q = [set(q_item) for q_item in q]
    for comb in combinations(range(1, n + 1), 5):
        flag = True
        for q_item, ans_item in zip(q, ans):
            cnt = 0
            for c in comb:
                if c in q_item:
                    cnt += 1
            if cnt != ans_item:
                flag = False
                break
        if flag:
            answer += 1

    return answer
