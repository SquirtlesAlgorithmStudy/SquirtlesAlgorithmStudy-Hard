# 백준 11659 구간 합 구하기 1

import sys
input = sys.stdin.readline #input()보다 데이터를 빠르게 입력을 처리할 수 있는 방식

N,M = map(int, input().split()) # N개숫자 M개줄
numbers = list(map(int,input.split()))

#누적합배열 초기화
prefix_sum_array = [0] * (N+1) #초기화한 0 포함하면 N+1개
for i in range(1, N+1):
    prefix_sum_array[i] = prefix_sum_array[i-1] + numbers[i-1]
    

#구간 합
result = []
for _ in range(M):
    i,j = map(int, input().split())
    result.append(prefix_sum_array[j] - prefix_sum_array[i-1])
    
