# 백준 2252 줄 세우기(위상정렬8_3)

from collections import deque

#1. 인접list구현
N,M = map(int, input().split()) #갯수, 연결
A = [[] for _ in range(N+1)]

#2. 진입차수 배열 구현
indegree = [0] * (N+1)
for i in range(M):
    S,E = map(int, input().split())
    A[S].append(E) #S와 E를 연결
    indegree[E] +=1 #E에 indegree가 있다는 말
    
#3. 위상정렬 수행
queue = deque()

#3-1. 진입차수 배열이 0인 노드를 조사하며 queue에 삽입 -> 빠져나가면서 현재 노드값을 출력
for i in range(1, N+1):
    if indegree[i] == 0:
        queue.append(i)

#3-2. 그 노드가 바라보고 있는 list의 data를 -1씩 -> 0이되면 queue에 넣어주기 
while queue:
    now = queue.popleft() #queue에서 맨위에 있는걸 뽑고
    print(now, end = ' ')
    for next in A[now]:
        indegree[next] -=1
        if indegree[next] ==0:
            queue.append(next)
