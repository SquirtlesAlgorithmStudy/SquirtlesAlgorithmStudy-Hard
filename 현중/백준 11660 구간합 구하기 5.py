#백준 11660 구간합 구하기 5

import sys
input = sys.stdin.readline

n,m = map(int, input().split()) # n : 리스트 크기 / m : 질의 수

A = [[0] *(n+1)]                    # 우선 1차원 배열로 원본배열 생성
D = [[0]*(n+1) for _ in range(n+1)] # 합배열은 2차원 배열로 생성

#row를 입력받아 원본 리스트A 데이터 저장
for i in range(n):
    A_row = [0] + [int(x) for x in input().split()]    
    A.append(A_row)

#2차원 배열을 돌며 구간 합 배열D 를 저장
for i in range(1, n+1):
    for j in range(1, n+1):
        D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j]
        
        
# 질의 입력
for _ in range(m): 
    x1, y1, x2, y2 = map(int, input().split())
    result = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1]
    print(result)