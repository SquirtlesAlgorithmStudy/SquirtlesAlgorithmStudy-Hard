# 백준 12965 평범한 배낭

import sys
input = sys.stdin.read
data = input().split()

# 입력 처리
N, K = int(data[0]), int(data[1])  # 물건 개수, 배낭 무게
items = []

index = 2
for _ in range(N):
    W, V = int(data[index]), int(data[index+1])
    items.append((W, V))
    index += 2

# DP 테이블 생성
dp = [[0] * (K + 1) for _ in range(N + 1)]

# DP 진행 (Knapsack Algorithm)
for i in range(1, N + 1):
    weight, value = items[i-1]  # 현재 아이템의 무게와 가치
    for w in range(K + 1):
        if w < weight:  # 현재 무게가 배낭 용량보다 크면 넣을 수 없음
            dp[i][w] = dp[i-1][w]
        else:  # 넣을 수 있다면 최댓값 선택
            dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight] + value)

# 정답 출력 (배낭 최대 가치)
print(dp[N][K])
