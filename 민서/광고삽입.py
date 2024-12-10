from itertools import accumulate
def hms2s(string):
    h, m, s = map(int, string.split(":"))
    return h * 3600 + m * 60 + s

def s2hms(s):
    m, s = s // 60, s % 60
    h, m = m // 60, m % 60
    return f"{h:02}:{m:02}:{s:02}"

def solution(play_time, adv_time, logs):
    play_time = hms2s(play_time)
    adv_time = hms2s(adv_time)
    diff = [0] * (play_time + 1)
    for l in logs:
        s, e = map(hms2s, l.split("-"))
        diff[s] += 1
        diff[e] -= 1
    times = accumulate(diff)
    acc_time = [0, *accumulate(times)]
    mx = 0
    ans = 0
    for i, (s, e) in enumerate(zip(acc_time, acc_time[adv_time:])):
        if e - s > mx:
            mx = e - s
            ans = i
    return s2hms(ans)
