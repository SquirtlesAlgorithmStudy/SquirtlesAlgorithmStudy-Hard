import sys
from collections import deque

# 입력 처리
input_data = sys.stdin.read().splitlines()
N, M = map(int, input_data[0].split())
grid = [list(map(int, input_data[i+1].split())) for i in range(N)]

def mark_external_air(grid, N, M):
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    
    # 외부 공기를 방문할 visited 배열
    visited = [[False]*M for _ in range(N)]
    queue = deque()
    
    # 가장자리의 0을 찾아서 BFS 시작점으로 추가
    for i in range(N):
        for j in range(M):
            if (i == 0 or j == 0 or i == N-1 or j == M-1) and grid[i][j] == 0:
                queue.append((i, j))
                visited[i][j] = True

    while queue:
        x, y = queue.popleft()
        
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and grid[nx][ny] == 0:
                visited[nx][ny] = True
                queue.append((nx, ny))
    
    return visited

def melt_ice(grid, N, M):
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    
    time = 0
    while True:
        # 외부 공기 구분 (내부 공기는 False, 외부 공기는 True)
        external_air = mark_external_air(grid, N, M)
        
        # 현재 존재하는 얼음 위치 찾기
        ice_list = [(i, j) for i in range(N) for j in range(M) if grid[i][j] == 1]
        
        if not ice_list:  
            return time
    
        melt_list = []
        for x, y in ice_list:
            contact = 0  
            
            for d in range(4):
                nx, ny = x + dx[d], y + dy[d]
                
                # 외부 공기와 맞닿아 있는 경우에만 녹음
                if 0 <= nx < N and 0 <= ny < M and grid[nx][ny] == 0 and external_air[nx][ny]:
                    contact += 1
            
            if contact >= 2:  # 외부 공기와 2개 이상 접촉하면 녹음
                melt_list.append((x, y))
        
        for x, y in melt_list:
            grid[x][y] = 0
        
        time += 1  

print(melt_ice(grid, N, M))
