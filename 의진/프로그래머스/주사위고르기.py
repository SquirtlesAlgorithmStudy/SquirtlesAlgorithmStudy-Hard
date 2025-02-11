from bisect import bisect_left, bisect_right
from itertools import combinations, product


def solution(dice):
    ans = []
    ans_score = -1
    history = set()

    n = int(len(dice) / 2)

    combi = list(combinations(range(0, len(dice)), n))

    for my_dice in combi:
        enemy_dice = list(set(range(len(dice))) - set(my_dice))
        if str(sorted(enemy_dice)) in history:
            continue
        history.add(str(sorted(list(my_dice))))

        my_score = []
        enemy_score = []

        for dice_cand in product(range(6), repeat=n):
            my_score.append(sum(dice[i][j] for i, j in zip(my_dice, dice_cand)))
            enemy_score.append(sum(dice[i][j] for i, j in zip(enemy_dice, dice_cand)))

        enemy_score.sort()
        can_win = sum(bisect_left(enemy_score, my) for my in my_score)
        can_lose = sum(
            len(enemy_score) - bisect_right(enemy_score, my) for my in my_score
        )

        if ans_score < can_win:
            ans = [dice + 1 for dice in my_dice]
            ans_score = can_win

        if ans_score < can_lose:
            ans = [dice + 1 for dice in enemy_dice]
            ans_score = can_lose

    return ans
