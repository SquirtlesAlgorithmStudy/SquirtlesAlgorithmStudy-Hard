# 백준 14501 퇴사(dp)

#1. 입력받기, dp테이블 만들기
N = int(input())
T = [0] * N
P = [0] * N

for i in range(N):
    T[i], P[i] = map(int, input().split())

dp = [0] * (N+1)

#2. 뒤에서 부터 상담이 가능하면 dp[n + T[n]] + p[n], 불가능하면 dp[n+1]

for n in range(N-1, -1, -1):
    if n + T[n] <= N:
        dp[n] = max(dp[n+1], dp[n+T[n]] + P[n])
    else:
        dp[n] = dp[n+1]
        
        
print(dp[0])