def book_time_2_minute(bt, idx):
    result = []
    for i, item in enumerate(bt):
        h, m = map(int, item.split(":"))
        if i == 0:
            result.append((60 * h + m, idx))
        else:
            result.append((60 * h + m + 9.9, idx))

    return tuple(result)


def solution(book_time):
    request_queue = []
    for idx, bt in enumerate(book_time):
        start, end = book_time_2_minute(bt, idx)
        request_queue.append(start)
        request_queue.append(end)

    request_queue.sort()

    info_list = [-1] * len(book_time)
    available = []
    answer = 0

    for request in request_queue:
        if info_list[request[1]] == -1:  # Start
            if len(available) == 0:
                info_list[request[1]] = answer
                answer += 1
            else:
                room = available.pop()
                info_list[request[1]] = room

        else:
            available.append(info_list[request[1]])

    return answer
