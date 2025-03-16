# Softeer Pipelined

import sys

input = sys.stdin.read
data = list(map(int, input().split()))

N = data[0]
times = data[1:]

max_time = max(times)

result = max_time + (N-1)
print(result)


# import sys

# input = sys.stdin.readline

# N = int(input())
# S = list(map(int, input().split()))

# print(N + max(S) -1)