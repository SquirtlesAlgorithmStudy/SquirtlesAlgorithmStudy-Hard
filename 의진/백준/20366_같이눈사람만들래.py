import sys
from itertools import combinations

input = sys.stdin.readline


def solution():
    N = int(input())
    H = list(map(int, input().split()))
    add_list = []

    for i, j in combinations(range(len(H)), 2):
        add_list.append((H[i] + H[j], i, j))
    add_list.sort()

    best_diff = float("inf")
    for left in range(len(add_list) - 1):
        right = left + 1
        while True:
            if (
                add_list[left][1] in add_list[right][1:]
                or add_list[left][2] in add_list[right][1:]
            ):
                right += 1
                if right == len(add_list):
                    break
                continue
            best_diff = min(add_list[right][0] - add_list[left][0], best_diff)
            break

    print(best_diff)


solution()
