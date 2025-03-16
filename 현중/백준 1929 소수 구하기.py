#백준 1929 소수 구하기
import math

#1. 초기화, list생성, idx값으로 초기화
M,N = map(int, input().split())
LIST = [0] * (N+1)

for i in range(2, N+1):
    LIST[i] = i
    
#2. root N까지 소수가 아니면 버리고, 소수의 배수값 버리고
for i in range(2, int(math.sqrt(N))+1):
    if LIST[i] ==0:
        continue
    for j in range(i+i, N+1, i):
        LIST[j] =0

#3. 소수인것을 출력 
for i in range(M,N+1):
    if LIST[i] !=0:
        print(LIST[i])