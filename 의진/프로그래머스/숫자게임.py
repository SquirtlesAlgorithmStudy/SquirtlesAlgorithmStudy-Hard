def solution(A, B):
    A.sort()
    B.sort()
    a_pointer = 0
    b_pointer = 0

    answer = 0
    while b_pointer < len(B):
        if A[a_pointer] < B[b_pointer]:
            answer += 1
            a_pointer += 1
            b_pointer += 1
        else:
            b_pointer += 1

    return answer
