from collections import deque
def solution(rc, operations):
    R = len(rc)
    C = len(rc[0])
    lcol = deque([rc[i][0] for i in range(R)])
    rcol = deque([rc[i][-1] for i in range(R)])
    rows = deque([deque([rc[i][j] for j in range(1, C - 1)]) for i in range(R)])
    for op in operations:
        if op == "ShiftRow":
            lcol.rotate(1)
            rcol.rotate(1)
            rows.rotate(1)
        elif op == "Rotate":
            rows[0].appendleft(lcol.popleft())
            rcol.appendleft(rows[0].pop())
            rows[-1].append(rcol.pop())
            lcol.append(rows[-1].popleft())
    answer = [[0] * C for _ in range(R)]
    for i, n in enumerate(lcol):
        answer[i][0] = n
    for i, n in enumerate(rcol):
        answer[i][-1] = n
    for i, r in enumerate(rows):
        for j, n in enumerate(r):
            answer[i][j + 1] = n
    return answer
