import sys
import copy

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

new_A = []

criterion = A[0] % 2

cnt = 0
for a in A:
    if a % 2 == criterion:
        cnt += 1
    else:
        new_A.append(cnt)
        criterion = 1 - criterion
        cnt = 1
new_A.append(cnt)

new_A_copy = copy.copy(new_A)
cnt = 0
flag = 0
for i in range(len(new_A) - 1):
    if flag == 0:
        cnt += new_A_copy[i] * new_A_copy[i + 1]
        new_A_copy[i], new_A_copy[i + 1] = new_A_copy[i + 1], new_A_copy[i]
        flag = 1 - flag
    else:
        A[i + 1] = A[i] + A[i + 1]
        flag = 1 - flag
answer = cnt

new_A_copy = copy.copy(new_A)
cnt = 0
flag = 1
for i in range(len(new_A) - 1):
    if flag == 0:
        cnt += new_A_copy[i] * new_A_copy[i + 1]
        new_A_copy[i], new_A_copy[i + 1] = new_A_copy[i + 1], new_A_copy[i]
        flag = 1 - flag
    else:
        A[i + 1] = A[i] + A[i + 1]
        flag = 1 - flag

answer = min(answer, cnt)


print(answer)
