# 백준 6236 용돈관리

import sys
#1. 입력, 초기화
N, M = map(int, sys.stdin.readline().split())
A = [int(sys.stdin.readline()) for _ in range(N)]

# 이진 탐색 범위 설정
start = max(A)  # 최소 인출 금액 (최대 하루 사용 금액 이상)
end = sum(A)    # 최대 인출 금액 (모든 돈을 한 번에 인출)

answer = end
#2, 이진탐색
while start <= end:
    mid = (start + end) // 2  # 현재 시도하는 인출 금액
    
    count = 1  # 인출 횟수 (최소 1번은 해야 함)
    current_money = mid  # 현재 보유 금액

    for expense in A:  
        if current_money < expense:  # 현재 금액이 부족하면 다시 인출
            count += 1
            current_money = mid  # 새로운 인출
        current_money -= expense  # 하루 사용
    
    if count > M:  # 너무 많이 인출했으면 (M번 초과) → 금액 늘리기
        start = mid + 1
    else:  # 인출 횟수가 M번 이하 → 더 작은 금액을 시도해볼 수 있음
        answer = mid
        end = mid - 1

print(answer)  # 최적의 인출 금액 출력