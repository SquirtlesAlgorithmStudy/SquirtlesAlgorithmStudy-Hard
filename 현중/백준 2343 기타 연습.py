# 백준 2343 기타 연습

#1. 초기화
N,M = map(int,input().split())
A = list(map(int,input().split()))

#2. i번 반복하며 블루레이의 크기 설정 start_idx(N의 최대), end_idx(총합)
start_idx = 0
end_idx = 0
for i in A:
    if start_idx < i:
        start_idx =i
    end_idx += i

#3. 이진탐색
while start_idx <= end_idx:
    mid_idx = int((start_idx + end_idx)/2)
    
    # 1. 블루레이 넣기
    sum =0
    count =0
    for i in range(N):
        if sum + A[i] > mid_idx:
            count += 1
            sum =0
        sum += A[i]
        
    # 2. 블루레이 갯수?    
    if sum !=0:
        count +=1
        
    # 3. 블루레이 범위 조정 27 -> 17 -> 21 -> 19 -> 20
    if count > M:
        start_idx = mid_idx +1
    else:
        end_idx = mid_idx -1
        
print(start_idx)