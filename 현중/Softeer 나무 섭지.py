#Softeer 나무 섭지

import sys
from collections import deque

#1. 입력처리
r,c = map(int, input().split())

grid = []
for _ in range(r):
    grid.append(list(input().strip()))

#2. 이동방향 결정
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

#3. 방문여부 초기화
queue = deque()
ghost = []
visited_namu = [[False] * c for _ in range(r)]
visited_ghost = [[False] * c for _ in range(r)]

#4. BFS탐색을 위해 queue초기화(남우를 먼저넣고 유령을 큐에 추가)
for row in range(r):
    for col in range(c):
        if grid[r][c] =='N':
            queue.append((r,c,'N'))
            visited_namu[r][c] = True
        elif grid[r][c] =='G':
            ghost.append((r,c,'G'))
            visited_ghost[r][c] = True

queue.extend(ghost)

5. BFS
6. 정답출력