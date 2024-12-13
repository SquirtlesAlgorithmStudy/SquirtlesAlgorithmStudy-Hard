def time_to_sec(time):
    h, m, s = map(int, time.split(":"))
    return 60 * 60 * h + 60 * m + s


def sec_to_time(sec):
    h = sec // 3600
    m = (sec % 3600) // 60
    s = (sec % 3600) % 60
    return f"{str(h).zfill(2)}:{str(m).zfill(2)}:{str(s).zfill(2)}"


def solution(play_time, adv_time, logs):
    pt = time_to_sec(play_time)
    diff = [0] * (pt + 2)
    time_block = [0] * (pt + 1)
    accu_time_block = [0] * (pt + 1)
    max_val = 0
    max_i = -1

    for log in logs:
        log = log.split("-")
        diff[time_to_sec(log[0])] += 1
        diff[time_to_sec(log[1])] -= 1

    for i in range(len(time_block)):
        if i == 0:
            time_block[i] = diff[i]
        else:
            time_block[i] = time_block[i - 1] + diff[i]

    for i in range(len(accu_time_block) - 1):
        accu_time_block[i + 1] = accu_time_block[i] + time_block[i]

    # try:
    #     print(accu_time_block[1549:1552])
    # except:
    #     pass

    for i in range(pt):
        if i + time_to_sec(adv_time) >= len(accu_time_block):
            break
        value = accu_time_block[i + time_to_sec(adv_time)] - accu_time_block[i]
        if max_val < value:
            # print(sec_to_time(i))
            max_val = value
            max_i = i

    answer = sec_to_time(max_i)
    return answer
