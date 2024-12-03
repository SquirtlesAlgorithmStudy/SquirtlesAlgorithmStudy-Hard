def solution(board, skill):
    N, M = len(board), len(board[0])
    diff = [[0] * (M + 1) for _ in range(N + 1)]
    for t, r1, c1, r2, c2, d in skill:
        if t == 1:
            d = -d
        r2, c2 = r2 + 1, c2 + 1
        diff[r1][c1] += d
        diff[r1][c2] -= d
        diff[r2][c1] -= d
        diff[r2][c2] += d
    for i in range(1, N):
        diff[i][0] += diff[i - 1][0]
    for j in range(1, M):
        diff[0][j] += diff[0][j - 1]
    for i in range(1, N):
        for j in range(1, M):
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1]
    answer = 0
    for i in range(0, N):
        for j in range(0, M):
            board[i][j] += diff[i][j]
            if board[i][j] > 0:
                answer += 1
    return answer
