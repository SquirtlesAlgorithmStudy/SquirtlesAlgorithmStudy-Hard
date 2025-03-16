# 백준 2178 미로 탐색하기
from collections import deque

#1. 초기화
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

N,M = map(int, input().split())
A = [[0]*M for _ in range(N)]
visited = [[False]*M for _ in range(N)]

#2. data받기
for i in range(N):
    numbers = list(input())
    for j in range(M):
        A[i][j] = int(numbers[j])
        
#3. bfs구현
def BFS(i,j):
    queue = deque()
    queue.append((i,j))
    visited[i][j] = True
    while queue:
        now = queue.popleft()
        for k in range(4):
            x = now[0] +dx[k]
            y = now[1] +dy[k]
            #1. 배열 나가면 안됌
            if x>=0 and y>=0 and x<N and y<M:
                #2. data가 0이면 안되고, visited면 안됌
                if A[x][y] !=0 and not visited[x][y]:
                    visited[x][y] = True
                    A[x][y] = A[now[0]][now[1]] +1
                    queue.append((x,y))
BFS(0,0)
print(A[N-1][M-1])