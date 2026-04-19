import sys
import math

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

cnt = 0
if N == 1:
    print(0)
else:
    cnt_arr = [0] * N
    for i in range(len(A) - 1):
        n = math.ceil(math.log2(A[i] / A[i + 1])) + cnt_arr[i - 1]
        if n > 0:
            cnt_arr[i] = n
            cnt += n

    print(cnt)
