import sys

input = sys.stdin.readline


def solution():
    N = int(input())
    A = list(map(int, input().split()))

    A.sort()

    left = 0
    right = len(A) - 1

    best = [float("inf"), 0]
    while left < right:
        new = A[left] + A[right]
        if new == 0:
            best = [0, 0]
            break

        if best[0] > abs(new):
            best[0] = abs(new)
            best[1] = new

        if new < 0:
            left += 1
        else:
            right -= 1

    print(best[1])


solution()
