def solution(A, B):
    A = sorted(A)
    B = sorted(B)
    i = len(A)
    answer = 0
    while i > 0:
        i -= 1
        if B[-1] > A[i]:
            answer += 1
            B.pop()
    return answer
