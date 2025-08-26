import sys

input = sys.stdin.readline

# 머리 / 가슴 / 배
# 머리 < 배 < 가슴

# 1. y 하나 정해놓기
# 2. mid까지 누적 합 < y까지의 누적 합 < y까지의 누적 합 - mid까지 누적 합 로 x를 찾으면서, 머리가 배보다 안 커질때까지의 개수 구하기

n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))

sums = [0]
for a in arr:
    sums.append(sums[-1] + a)
del sums[0]

result = 0
for y in range(1, n - 1):
    stomSum = sums[-1] - sums[y]  # y까지의 누적합

    start = 0
    end = y - 1
    if start == end:
        if sums[0] < stomSum < sums[y] - sums[0]:
            result += 1
    else:
        cnt = 0
        already = 0
        while start <= end:
            mid = (start + end) // 2
            if sums[mid] < stomSum < sums[y] - sums[mid]:
                result += mid + 1 - already  # mid + 1 부터 계속 더 탐색하기
                already = mid + 1
                start = mid + 1
            else:
                end = mid - 1

print(result)
