def count_remaining_destroyers(n, m, grid, attacks):
    # 각 행의 1의 개수를 세어 저장
    row_counts = [row.count(1) for row in grid]

    # 각 공격에 대해 처리
    for L, R in attacks:
        for i in range(L - 1, R):  # 행 인덱스는 0부터 시작하므로 L-1부터 R-1까지
            if row_counts[i] > 0:
                row_counts[i] -= 1  # 가장 왼쪽의 1을 제거

    # 남아있는 1의 총 개수 계산
    return sum(row_counts)

# 입력 처리
n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
attacks = [tuple(map(int, input().split())) for _ in range(2)]

# 결과 출력
print(count_remaining_destroyers(n, m, grid, attacks))
