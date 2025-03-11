# 백준 17298 오큰수 구하기
import sys

n = int(input())
answer = [0] * n

A = list(map(int, input().split()))
Stack = []

for i in range(n):
    #오큰수 조건: stack이 비어있지 않고, stack의 top_idx_data가 new_idx_data보다 작으면
    while Stack and A[Stack[-1]] < A[i]:
        #1. top을 pop하고 2. new_idx_data를 append하여 answer list에 오큰수 저장
        answer[Stack.pop()] = A[i]
    Stack.append(i)
    
while Stack:
    answer[Stack.pop()] = -1

result = ""

for i in range(n):
    result += str(answer[i])+" "
    
print(result)
