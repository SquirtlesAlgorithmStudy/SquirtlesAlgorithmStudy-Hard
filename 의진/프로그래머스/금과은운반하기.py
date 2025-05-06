def do_test(time, a, b, g, s, w, t):
    gold = 0
    silver = 0
    total = 0

    for i in range(len(g)):
        now_gold = g[i]
        now_silver = s[i]
        now_weight = w[i]
        now_time = t[i]

        # 주어진 시간 내 이동 횟수 계산 (왕복)
        move_cnt = time // (now_time * 2)

        # 편도 추가
        if time % (now_time * 2) >= now_time:
            move_cnt += 1

        # 최대 운반 가능 무게
        possible_move_weight = move_cnt * now_weight

        # 금, 은, 총량 계산
        gold += min(now_gold, possible_move_weight)
        silver += min(now_silver, possible_move_weight)
        total += min(now_gold + now_silver, possible_move_weight)

    # 목표 달성 가능 여부 반환
    return total >= a + b and gold >= a and silver >= b


def solution(a, b, g, s, w, t):
    start = 0
    # 최악의 경우 계산
    end = (10**9) * (10**5) * 4

    while start <= end:
        mid = (start + end) // 2
        if do_test(mid, a, b, g, s, w, t):
            end = mid - 1
        else:
            start = mid + 1

    return start
