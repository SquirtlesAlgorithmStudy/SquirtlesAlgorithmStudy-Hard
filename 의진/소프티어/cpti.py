from collections import Counter
from itertools import combinations
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
cpti_list = [int(input().strip(), 2) for _ in range(N)]

counter = Counter(cpti_list)
result = 0

for cpti in cpti_list:
    result += counter[cpti] - 1

    for i in range(M):
        if cpti % (1 << (i + 1)) >= (1 << i):
            new_cpti = cpti - (1 << i)
        else:
            new_cpti = cpti + (1 << i)

        result += counter[new_cpti]

    for i, j in combinations(range(M), 2):
        new_cpti = cpti
        for idx in [i, j]:
            if cpti % (1 << (idx + 1)) >= (1 << idx):
                new_cpti = new_cpti - (1 << idx)
            else:
                new_cpti = new_cpti + (1 << idx)
        result += counter[new_cpti]

result //= 2
print(result)
