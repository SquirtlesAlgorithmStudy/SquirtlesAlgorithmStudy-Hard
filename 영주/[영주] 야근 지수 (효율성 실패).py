def solution(n, works):
    while n > 0:
        index = works.index(max(works))
        if works[index] <= 0:
            break
        works[index] -= 1
        n -= 1
    
    answer = 0
    for i in works:
        if i>0:
            answer += i**2
    
    return answer
