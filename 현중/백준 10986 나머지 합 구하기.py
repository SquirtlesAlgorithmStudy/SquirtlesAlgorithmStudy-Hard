# 백준 10986 나머지 합 구하기

import sys
input = sys.stdin.readline()

n,m = map(int, input().split())
A = list(map(int, input().split())) #원본배열을 list 형태로 입력받아
S = [0] * n

C = [0] * m  #m으로 나누었을 때, 같은 나머지값을 count 하는 list

answer =0

#합배열 구하기
S[0] = A[0]
for i in range(1,n):
    S[i] = S[i+1] + A[i]
    
#m으로 업데이트 
for i in range(0,n):
    remainder = S[i] %m
    # 1. 나머지가 0이 나오면 answer에 업데이트
    if remainder ==0:
        answer +=1
    #2. 같은 나머지 값을 갖는 수의 갯수를 count배열에 업데이트
    C[remainder] +=1
    
#C배열의 값이 1보다 크며(같은 나머지 값을 갖는 것이 2개이상 있으면 combination하여 answer에 update)
for i in range(m):
    if C[i] >1:
        answer += (C[i]*(C[i]-1) //2)  #combination공식!

print(answer)