import sys
import math

input = sys.stdin.readline
N = int(input())
seq = list(map(int, input().split()))

multiply_list = []
prefix_sum = [0]
seq_sum = sum(seq)
if seq_sum % 4 != 0:
    print(0)
    sys.exit()

divider = seq_sum // 4

if divider != 0:
    for s in seq:
        prefix_sum.append(prefix_sum[-1] + s)
        if prefix_sum[-1] % divider == 0 and prefix_sum[-1] < seq_sum:
            multiply_list.append(prefix_sum[-1])

    first = divider
    second = divider * 2
    third = divider * 3
    cnt = 0
    add_item = 0
    ans = 0

    for m in multiply_list:
        if m == first:
            cnt += 1
        elif m == second:
            add_item += cnt
        elif m == third:
            ans += add_item
    print(ans)

else:
    for s in seq:
        prefix_sum.append(prefix_sum[-1] + s)
        if prefix_sum[-1] == 0:
            multiply_list.append(prefix_sum[-1])

    print(math.comb(len(multiply_list) - 1, 3))
