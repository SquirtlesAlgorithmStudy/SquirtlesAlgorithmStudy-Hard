from sys import stdin

# 1. 입력처리
n= int(stdin.readline())
black_size = list(map(int, stdin.readline().split()))
black_size.sort()

# 2. 최대 갯수?저장할 변수
many =0

# 3. 2~연탄 크기를 돌며 값구하기
for i in range(2, max(black_size)+1):
    cnt = 0 # 공약수로 나누어 떨어지는 갯수 cnt
    for j in range(n):
        if black_size[j] % i ==0:
            cnt+=1
    many = max(many, cnt)

print(many)