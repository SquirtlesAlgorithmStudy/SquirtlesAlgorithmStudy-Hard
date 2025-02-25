import sys

input = sys.stdin.readline

N = int(input())
S = list(map(int, input().split()))

print(N + max(S) - 1)
