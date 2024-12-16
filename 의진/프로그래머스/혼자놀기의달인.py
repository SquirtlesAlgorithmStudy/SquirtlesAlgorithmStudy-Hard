import copy


def get_group(cards, number):
    new_cards = copy.copy(cards)
    group = []
    next_num = number

    while True:
        if new_cards[next_num - 1] == -1:
            return new_cards, group

        new_next_num = cards[next_num - 1]
        new_cards[next_num - 1] = -1
        group.append(next_num)
        next_num = new_next_num


def solution(cards):
    answer = 0
    for i in range(len(cards)):
        for j in range(i + 1, len(cards)):
            test_cards = copy.copy(cards)
            new_cards, group1 = get_group(test_cards, i)
            if new_cards[j] == -1:
                continue
            new_cards, group2 = get_group(new_cards, j)
            answer = max(answer, len(group1) * len(group2))

    return answer
