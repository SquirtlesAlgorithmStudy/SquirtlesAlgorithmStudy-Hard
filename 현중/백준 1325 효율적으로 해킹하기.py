# 백준 1325 효율적으로 해킹하기
import sys
from collections import deque
input = sys.stdin.readline

N,M = map(int, input().split())
#1. 인접리트스 만들기
A = [[] for _ in range(N+1)]
answer = [0] * (N+1)

#2. BFS를 이용하여 탐색을   수행
def BFS(v):
    visited = [False] * (N + 1)
    queue = deque()
    queue.append(v)
    visited[v] = True
    
    while queue:
        now_Node = queue.popleft()
        for i in A[now_Node]:
            if not visited[i]:
                visited[i] = True
                answer[i] += 1 
                queue.append(i)

#3. 신뢰도list 최대값을 sort한 후 최대값 출력
for i in range(M):
    S, E = map(int, input().split())
    A[S].append(E)

for i in range(1, N + 1): 
    BFS(i)
    
maxVal = max(answer)
for i in range(1, N + 1):
    if maxVal == answer[i]:
        print(i, end=' ')  