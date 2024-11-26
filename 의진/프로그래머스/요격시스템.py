def solution(targets):
    targets.sort()
    cnt = 0
    for i, target in enumerate(targets):
        if i == 0:
            pivot_e = target[1]
            cnt += 1
            continue

        if target[0] < pivot_e:
            pivot_e = target[1]
            continue
        else:
            pivot_e = target[1]
            cnt += 1

    return cnt
