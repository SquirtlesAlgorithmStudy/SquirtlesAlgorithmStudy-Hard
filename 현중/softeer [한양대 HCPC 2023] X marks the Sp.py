# softeer [한양대 HCPC 2023] X marks the Spot

import sys
#1. 초기화
input = sys.stdin.readline

N = int(input().strip())
result = []

for _ in range(N):
    S,T = input().strip().split() # 양쪽 공백을 제거, 공백을 기준으로 입력값을 나누어 저장
    P = S.find('x')
    if 'x' in S:
        P = S.find('x')
    else:
        P = S.find('X')

    result.append(T[P].upper())

print(''.join(result))

