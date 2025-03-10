import sys
import math
from functools import reduce

sys.setrecursionlimit(10**9)

input = sys.stdin.readline

N = int(input())
seq = [0] + list(map(int, input().split()))


def dfs(now, visited, cnt, seq):
    visited[now] = True
    if not visited[seq[now]]:
        return dfs(seq[now], visited, cnt + 1, seq)
    else:
        return cnt


def lcm_list(numbers):
    if not numbers:
        return None
    return reduce(math.lcm, numbers)


visited = [False] * (N + 1)
values = []


for i in range(1, N + 1):
    if not visited[i]:
        values.append(dfs(i, visited, 1, seq))

print(lcm_list(values))
