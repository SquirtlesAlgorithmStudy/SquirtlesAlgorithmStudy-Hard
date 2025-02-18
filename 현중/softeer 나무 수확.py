# softeer 나무 수확

import sys
input = sys.stdin.readline

# 1️⃣ 입력 처리
N = int(input().strip())
graph = [list(map(int, input().split())) for _ in range(N)]

# 2️⃣ DP 테이블 초기화
dp = [[[0, 0] for _ in range(N)] for _ in range(N)]

# 3️⃣ 시작점 초기화
dp[0][0][0] = graph[0][0]
dp[0][0][1] = 2 * graph[0][0]

# 4️⃣ DP 점화식 계산
for i in range(N):
    for j in range(N):
        # 스프링쿨러를 사용하지 않은 경우
        if i > 0:
            dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0] + graph[i][j])
        if j > 0:
            dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0] + graph[i][j])
        
        # 스프링쿨러를 사용한 경우
        if i > 0:
            dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + graph[i][j])
            dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0] + graph[i][j] * 2)
        if j > 0:
            dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][1] + graph[i][j])
            dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0] + graph[i][j] * 2)
        
        # 현재 칸에서 스프링쿨러를 처음 설치한 경우
        dp[i][j][1] = max(dp[i][j][1], 2 * graph[i][j])

# 5️⃣ 결과 출력
print(dp[N-1][N-1][1])
