# 백준 1260 DFS, BFS 프로그램

#1. 초기화
from collections import deque
N,M,Start = map(int, input().split())
A = [[] for _ in range(N+1)]

#2. 그래프 연결
for _ in range(M):
    s,e = map(int, input().split())
    A[s].append(e)
    A[e].append(s)

#3. 요구사항 처리(작은 수 node부터)
for i in range(N+1):
    A[i].sort()
    
#4. dfs, visited_list초기화
def dfs(start_node):
    print(start_node, end=' ') # end='' : 줄바꿈 없음
    visited[start_node] = True
    for i in A[start_node]:
        if not visited[i]:
            dfs(i)

visited = [False] * (N+1)
dfs(Start)

#5. bfs, visited_list초기화
def bfs(start_node):
    queue = deque()
    #queue를 넣어주기 + visited처리
    queue.append(start_node)
    visited[start_node] = True
    
    while queue:
        now_node = queue.popleft()
        print(now_node, end=' ') # end='' : 줄바꿈 없음
        for i in A[now_node]:
            if not visited[i]:
                visited[i] = True
                queue.append(i)
                
print() #dfs이후 bfs 줄바꿈을 해주기 위해
visited = [False] * (N+1)
bfs(Start)