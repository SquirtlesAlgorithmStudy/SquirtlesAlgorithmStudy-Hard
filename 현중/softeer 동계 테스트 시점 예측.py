# 동계 테스트 시점 예측

import sys
from collections import deque

input_data = sys.stdin.read().splitlines()

N,M = map(int, input_data[0].split())
grid = [list(map(int, input_data[i+1].split())) for i in range(N)]

def melt_ice(grid, N, M):
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    
    time =0
    while True:
        ice_list = [(i,j) for i in range(N) for j in range(M) if grid[i][j] ==1]
        if not ice_list:
            return time #얼음이 다 녹았을 때 시간
    
        queue = deque(ice_list)
        visited = [[False]*M for _ in range(N)]
        
        melt_list = []
        for x,y in ice_list:
            contact = 0 #외부 공기와 접촉이 2개 이상
            for d in range(4):
                nx, ny = x + dx[d], y + dy[d]
                if 0 <= nx < N and 0 <= ny < M and grid[nx][ny] ==0:
                    contact +=1
                    
            if contact >=2:
                melt_list.append((x,y))
                

        for x,y in melt_list:
            grid[x][y] =0
            
        time +=1
        
print(melt_ice(grid, N, M))
