# softeer 진정한 효도

import sys

# 1️⃣ 입력 처리
input = sys.stdin.readline
cost = []
matrix = [list(map(int, input().split())) for _ in range(3)]  # 3×3 행렬 입력받기

# 2️⃣ 행과 열의 "최대값 - 최소값" 계산
for i in range(3):
    cost.append(max(matrix[i]) - min(matrix[i]))  # i번째 행에서 최대-최소 차이 저장
    column = [matrix[j][i] for j in range(3)]  # i번째 열 데이터 추출
    cost.append(max(column) - min(column))  # i번째 열에서 최대-최소 차이 저장

# 3️⃣ 최솟값 출력
print(min(cost))
