import sys

input = sys.stdin.readline

N = int(input())
micro = [(int(x), i + 1) for i, x in enumerate(input().split())]
INF = float("inf")

micro = [(INF, 0)] + micro + [(INF, len(micro))]

while len(micro) != 3:
    new_micro = [(INF, 0)]
    for i in range(1, len(micro) - 1):
        accum = micro[i][0]
        idx = micro[i][1]
        if new_micro[-1][0] <= micro[i][0]:
            accum += new_micro[-1][0]
            new_micro.pop()
        if micro[i + 1][0] <= micro[i][0]:
            accum += micro[i + 1][0]
            micro[i + 1] = (-1, micro[i + 1][1])
        if accum > 0:
            new_micro.append((accum, idx))
    micro = new_micro + [(INF, len(new_micro))]

print(micro[1][0])
print(micro[1][1])
