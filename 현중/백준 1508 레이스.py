# 백준 1508 레이스
import sys

input = sys.stdin.readline

#1. 입력받기
N,M,K = map(int, input().split())
positions = list(map(int, input().split()))

#2. 이진탐색하며 최소/최대거리 설정
positions.sort()
left, right = 1, positions[-1] - positions[0]
best_D = 1

#3. 이진탐색 실행
while left <=right:
    mid = (left + right)//2
    count =1
    recentput_position = positions[0]
    
    #1. 그리디를 돌며 M명이 배치될 수 있는지 확인
    for pos in positions:
        if pos - recentput_position >=mid:
            count +=1
            recentput_position = pos
            
    #2. 더 큰 D가 잇을까?
    if count >=M:
        best_D = mid
        left = mid+1
    else:
        right = mid-1
        
#4. 최적의 D를 찾았으면 심판을 배치 및 출력
result = [0] * K
count =0
recentput_position = positions[0]

for i in range(K):
    if count < M and (i ==0 or positions[i] - recentput_position >= best_D):
        result[i] = '1'
        recentput_position = positions[i]
        count +=1
        
print("".join(result))