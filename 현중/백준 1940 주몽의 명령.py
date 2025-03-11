# 백준 1940 주몽의 명령

import sys
input = sys.stdin.readline
N = int(input()) #재료 갯수
M = int(input()) #이상?

L = list(map(int, input().split()))
L.sort()

answer =0
start_idx = 0
end_idx = N-1

while start_idx < end_idx:
    if L[start_idx] + L[end_idx] < M:
        start_idx +=1
    elif L[start_idx] + L[end_idx] > M:
        end_idx -= 1
    else : # start_idx + end_idx = M면 start 증가, end 감소
        answer +=1
        start_idx += 1
        end_idx -= 1
        
print(answer)