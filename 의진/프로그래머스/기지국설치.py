def solution(n, stations, w):
    cnt_list = []
    offset = 1

    for station in stations:
        cnt_list.append(station - w - offset)
        offset = station + w + 1

    if offset <= n:
        cnt_list.append(n - offset + 1)

    answer = 0
    # print(cnt_list)
    for c in cnt_list:
        if c != 0:
            answer += (c - 1) // (2 * w + 1) + 1

    return answer
