import sys

input = sys.stdin.readline

N = int(input())
cards = list(map(int, input().split()))
prefix_sum_even = [0]
prefix_sum_odd = [0]

for i, card in enumerate(cards):
    if i % 2 == 0:
        prefix_sum_even.append(prefix_sum_even[-1] + card)
    else:
        prefix_sum_odd.append(prefix_sum_odd[-1] + card)


def get_sum(prefix_sum, left, right):
    return prefix_sum[right + 1] - prefix_sum[left]


result = 0

for i in range(N // 2 - 1):
    result = max(
        result,
        get_sum(prefix_sum_even, 0, i) + get_sum(prefix_sum_odd, i + 1, N // 2 - 1),
    )

    result = max(
        result, get_sum(prefix_sum_even, 0, i) + get_sum(prefix_sum_odd, i, N // 2 - 2)
    )

result = max(result, get_sum(prefix_sum_odd, 0, N // 2 - 1))
result = max(result, get_sum(prefix_sum_even, 0, N // 2 - 1))

print(result)
