input = open(0).readline
N = int(input())
s = [*map(int, input().split())]
print(max(s) + len(s) - 1)
