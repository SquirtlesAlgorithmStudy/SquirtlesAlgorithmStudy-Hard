# 백준 1717 집합 표현하기 
import sys
input = sys.stdin.readline #입력데이터가 백만개 이상
sys.setrecursionlimit(100000) #재귀함수 사용할 때

#1. 대표노드 만들기, 대표노드를 자기자신으로 초기화
N,M = map(int,input().split())
parent = [0] * (N+1)             #대표노드 저장하는 배열

for i in range(0, N+1):
    parent[i] = i


#3. union연산 구연(대표 노드 찾아서)
def union(a,b): 
    a= find(a)
    b= find(b)
    if a !=b:
        parent[b] =a


#4. find연산 구연(대표노드면 return, 아니면 재귀&경로압축)
def find(a):
    if a == parent[a]:
        return a
    else:
        parent[a] = find(parent[a]) # 여기가 핵심임
        return parent[a]
    
#5. 두 원소가 같은 집합인지 확인
def checkSame(a,b):
    a = find(a)
    b = find(b)
    if a==b:
        return True
    return False

#2. 질의 앞이 0나오면 합집합, 1이면 같은 집합 원소인지 확인
for i in range(M):
    question, a, b = map(int, input().split())
    if question ==0:
        union(a,b)
    else: # 6. 
        if checkSame(a,b):
            print("YES")
        else:
            print("NO")