import sys

input = sys.stdin.readline

N = int(input())
S = input().strip()

prefix_sum = [[0] for _ in range(4)]
dksh = "DKSH"

for s in S:
    for i in range(4):
        if s == dksh[i]:
            if i == 0:
                prefix_sum[i].append(prefix_sum[i][-1] + 1)
            else:
                prefix_sum[i].append(prefix_sum[i][-1] + prefix_sum[i - 1][-1])

print(prefix_sum[-1][-1])
