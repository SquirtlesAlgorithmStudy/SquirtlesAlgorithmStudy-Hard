import sys

input = sys.stdin.readline

test_cases = []

while True:
    try:
        x = int(input())
        n = int(input())
        l = tuple(int(input()) for _ in range(n))
        test_cases.append((x, n, l))
    except:
        break

for t in test_cases:
    x = t[0]
    n = t[1]
    l = list(t[2])

    l.sort()
    left = 0
    right = len(l) - 1
    x *= 10_000_000
    result = None

    while left < right:
        sum_val = l[left] + l[right]
        if sum_val == x:
            result = ("yes", l[left], l[right])
            break
        elif sum_val < x:
            left += 1
        else:
            right -= 1

    if result is None:
        result = "danger"

    if isinstance(result, str):
        print(result)
    else:
        print(*result)
