from collections import deque

def solution(board):
    answer = 0
    rows, cols = len(board), len(board[0])
    start = []
    now = []
    goal = []
    path = deque()
    visited = []
    
    for _ in range(rows):
        visited.append([False] * cols)

    for i, row in enumerate(board):
        if 'R' in row:
            j = row.index('R')
            start = [i, j, 0]
            now = start
            visited[i][j] = True
        if 'G' in row:
            j = row.index('G')
            goal = [i, j]

    while True:
        r, c, distance = now
        distance += 1

        for i in range(r, rows):
            if board[i][c] == 'D':
                path.append([i - 1, c, distance])
                break
            elif i == rows - 1:
                path.append([rows - 1, c, distance])
                break

        for i in range(r, -1, -1):
            if board[i][c] == 'D':
                path.append([i + 1, c, distance])
                break
            elif i == 0:
                path.append([0, c, distance])
                break

        for i in range(c, cols):
            if board[r][i] == 'D':
                path.append([r, i - 1, distance])
                break
            elif i == cols - 1:
                path.append([r, cols - 1, distance])
                break

        for i in range(c, -1, -1):
            if board[r][i] == 'D':
                path.append([r, i + 1, distance])
                break
            elif i == 0:
                path.append([r, 0, distance])
                break
        
        while True:
            if len(path) != 0:
                now = path.popleft()
            else:
                return -1
            
            if not visited[now[0]][now[1]]:
                visited[now[0]][now[1]] = True
                break

        if goal[0] == now[0] and goal[1] == now[1]:
            answer = now[2]
            break
            
    return answer
