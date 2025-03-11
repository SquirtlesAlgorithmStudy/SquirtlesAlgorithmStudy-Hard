#백준 11724 연결 요소의 개수 구하기

import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

n,m = map(int, input().split())

A = [[] for _ in range(n+1)]  #그래프 저장 인접 리스트 
visited = [False] * (n+1)

#1. visited 처리(엣지 양 끝점 u, v)
def dfs(v):
    visited[v] = True
    for i in A[v]:          # 현재node = 방문node
        if not visited[i]:  #            방문node 아니면 현재i를 기준으로 dfs
            dfs(i)

#2.노드 그래프 그리기(인접list에 그래프 데이터 저장)(노드갯수 n, 엣지갯수 m)
for _ in range(m):
    s,e = map(int, input().split())
    A[s].append(e) #방향이없기에 시작점 -> 종료점, 종료점 -> 시작점 가능
    A[e].append(s)

count =0 

#3. 정답구하기
for i in range(1,n+1): 
    if not visited[i]:# n번 반복하며 방문하지 않은 node가 있으면  
        count +=1
        dfs(i)

print(count)