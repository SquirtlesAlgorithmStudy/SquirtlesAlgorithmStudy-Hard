def solution(intervals):
    up_set = set()
    down_set = set()
    max_val = 0
    for interval in intervals:
        up_set.add(interval[0])
        down_set.add(interval[1])
        max_val = max(max_val, interval[1])

    current = 0
    pos_flag = False
    result = []
    for i in range(max_val + 1):
        if i in up_set:
            current += 1
        if i in down_set:
            current -= 1

        if not pos_flag and current > 0:
            pos_flag = True
            start = i

        elif pos_flag and current == 0:
            pos_flag = False
            end = i
            result.append((start, end))

    return result


print(solution([(1, 3), (5, 8), (4, 10), (20, 25)]))
