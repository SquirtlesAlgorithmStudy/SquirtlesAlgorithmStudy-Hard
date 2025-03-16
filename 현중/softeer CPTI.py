# Softeer CPTI
import sys
from collections import Counter
from itertools import combinations

input = sys.stdin.readline
#1.입력받기
N,M = map(int, input().split())
cpti_list = [int(input().strip(), 2) for _ in range(N)]

counter = Counter(cpti_list) # Counter({1: 2, 2: 1, 3: 1})

#2. 모든 CPTI값에 대해 친밀한관계찾기
result =0
for cpti in cpti_list:
    result += counter[cpti] -1 #동일한 cpit끼리 쌍을 계산하고 자기자신끼리 -1
    
    for i in range(M):         #1bit차이 cpti 찾기
        new_cpti = cpti ^ (1<<i)
        result += counter[new_cpti]
        
    for i, j in combinations(range(M), 2): #2bit차이 cpti 찾기 / 0~M-1숫자중 2개뽑는 경우의 수
        new_cpti = cpti ^ (1<<i) ^ (1<<j)
        result += counter[new_cpti]
        
result //=2 #1-2, 2-1 중복
print(result)