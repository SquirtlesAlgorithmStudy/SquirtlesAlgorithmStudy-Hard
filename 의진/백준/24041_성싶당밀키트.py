import sys

input = sys.stdin.readline

N, G, K = map(int, input().split())
S = []
L = []
O = []

for _ in range(N):
    items = tuple(map(int, input().split()))
    S.append(items[0])
    L.append(items[1])
    O.append(items[2])


def do_test(mid):
    result = 0
    for alive in alives:
        if alive[0] < mid:
            print(alive[0])
            result += (mid - alive[0]) * alive[1]

    return result > G


while start <= end:
    mid = (start + end) // 2
    if do_test(mid):
        start = mid + 1
    else:
        end = mid - 1

print(mid)
