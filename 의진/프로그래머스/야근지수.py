def solution(n, works):
    max_work = max(works)
    info_list = [0] * (max_work + 1)
    for work in works:
        info_list[work] += 1

    cur_N = n
    for i, item in enumerate(reversed(info_list)):
        i = len(info_list) - i - 1
        if i > 0:
            if cur_N >= item:
                cur_N -= item
                info_list[i] -= item
                info_list[i - 1] += item

            else:
                info_list[i] -= cur_N
                info_list[i - 1] += cur_N
                break

        else:
            break

    answer = 0
    # print(rw_dict)
    for i, item in enumerate(info_list):
        answer += (i**2) * item

    return answer
