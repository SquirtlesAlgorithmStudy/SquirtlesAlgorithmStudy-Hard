# 백준 1377 버블 정렬 프로그램1 

# swap이 몇번 일어나냐?!, 시간복잡도가 초과하기에 nlogn으로 풀어야 -> (버블정령의 swap이 언제 안일어나? 찾기)
# C++코드를 보면 True 1~N-i까지 swap이 일어나고 마지막에 Fasle가 나기에 swap+1번 돌고 출력

import sys
input = sys.stdin.readline

N = int(input())
A = [] #idx형태로 저장해보자 <pair<int,int>>

for i in range(N): 
    A.append((int(input()),i)) #idx가 중요하기 때문에 i값을 받고
    
Max =0
sorted_A = sorted(A)           #sort를 돌리는데

for i in range(N):
    if Max < sorted_A[i][1] -i: #정렬 전 idx - 정렬 후 idx
        Max = sorted_A[i][1] -i #현재 max인 뺀 값을 가져옴 
        
print(Max + 1) # 마지막에 false가 나와 한번도 안돈 것이 있기에