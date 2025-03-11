# 백준 1920 원하는 정수 찾기

#1. 초기화, 이진탐색은 정렬해줘야함
N = int(input())
A = list(map(int, input().split()))
A.sort()

M = int(input())
target_list = list(map(int, input().split()))

#2, M개 만큼 반복하며 이진탐색해줘야
for i in range(M):
    find = False
    target = target_list[i]
    
    start_idx =0
    end_idx = len(A)-1
    
    while start_idx <=end_idx:
        mid_idx = int((start_idx + end_idx)/2)
        mid_value = A[mid_idx]
        if mid_value > target:
            end_idx = mid_idx -1
        elif mid_value < target:
            start_idx = mid_idx +1
        else:
            find = True
            break
    if find:
        print(1)
    else:
        print(0)
        
        
        