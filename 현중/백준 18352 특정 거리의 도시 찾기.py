# 백준 18352 특정 거리의 도시 찾기
import sys
from collections import deque
input = sys.stdin.readline

#1. 도시와 도로 구현
N,M,K,X = map(int,input().split())
A = [[] for _ in range(N+1)]
answer = [] # K와 같은 도시의 번호
visited = [-1] * (N+1)

#2. BFS 탐색하며 최단 거리값을 방문리스트 queue에 저장(간선거리가 일정하면 웬만하면 BFS)
def BFS(v):
    queue = deque()
    queue.append(v)
    visited[v] +=1
    
    while queue:
        now_node = queue.popleft()
        for i in A[now_node]:
            if visited[i] == -1:
                visited[i] = visited[now_node] +1
                queue.append(i)

#3. 그래프 데이터 저장
for _ in range(M):
    S,E = map(int, input().split())
    A[S].append(E)

BFS(X)
#4.방문거리가 K인 노드의 숫자를 answer list에 대해서 값이 k가 되면 그의 idx 출력  
for i in range(N+1):
    if visited[i] == K:
        answer.append(i)
        
if not answer:
    print(-1)
else:
    answer.sort()
    for i in answer:
        print(i)