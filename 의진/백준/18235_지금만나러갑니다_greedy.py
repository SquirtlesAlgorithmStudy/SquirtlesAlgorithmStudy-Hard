import sys
import math
from collections import deque

input = sys.stdin.readline


def solution():
    N, A, B = map(int, input().split())
    new_A = min(A, B)
    new_B = max(A, B)
    A = new_A
    B = new_B

    if (B - A) % 2 == 1:
        return -1

    dist = B - A
    adders = []
    half_dist = dist // 2
    while half_dist > 0:
        lowest_bit = half_dist & -half_dist
        adders.append(lowest_bit)
        half_dist -= lowest_bit

    i = 1
    now_A = A
    now_B = B
    queue = deque()
    queue.append((now_A, now_B, 0, 0))
    while queue:
        now_A, now_B, count, adders_pointer = queue.popleft()
        i = 2**count
        if i == adders[adders_pointer]:
            queue.append((now_A + i, now_B - i, count + 1, adders_pointer + 1))
            if adders_pointer == len(adders) - 1:
                return count + 1
        else:
            if now_A - i > 0:
                queue.append((now_A - i, now_B - i, count + 1, adders_pointer))

            if now_B + i <= N:
                queue.append((now_A + i, now_B + i, count + 1, adders_pointer))

    return -1


print(solution())
