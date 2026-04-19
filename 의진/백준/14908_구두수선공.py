import sys

input = sys.stdin.readline


def solution():
    N = int(input())
    items = sorted(
        [tuple([i + 1]) + tuple(map(int, input().split())) for i in range(N)],
        key=lambda x: (-(x[2] / x[1]), x[0]),
    )
    print(*[items[i][0] for i in range(len(items))])


solution()
