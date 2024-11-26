def solution(targets):
    targets.sort()
    
    answer = 0
    end = 0
    for s,e in targets:
        if s<end:
            end = min(e, end)
            continue
        else:
            answer += 1
            end = e
    
    return answer
