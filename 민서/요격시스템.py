def solution(targets):
    targets = sorted(targets)
    i = 0
    answer = 0
    while i < len(targets):
        end = targets[i][1]
        while i < len(targets) and targets[i][0] < end:
            if targets[i][1] < end:
                end = targets[i][1]
            i += 1
        answer += 1
    return answer
