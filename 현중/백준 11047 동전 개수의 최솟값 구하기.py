# 백준 11047 동전 개수의 최솟값 구하기

#1. 초기화
N,K = map(int, input().split()) #동전갯수, 목표금액
A = [0] * N

#2. N만큼 반복하며 A list 저장
for i in range(N):
    A[i] = int(input())
    
#3. 내림차순으로 N번(N-1 ~ 0) 반복하여 K보다 작거나 같으면 나눠 몫을 count, 남은 돈 update 
count =0
for i in range(N-1, -1, -1): #for i in range(start, stop, step)
    if A[i] <= K:
        count += int(K/A[i])
        K = K % A[i]
        
print(count)