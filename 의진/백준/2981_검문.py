import sys
import math

input = sys.stdin.readline

N = int(input())

numbers = [int(input()) for _ in range(N)]
numbers.sort()

diff_list = [numbers[i + 1] - numbers[i] for i in range(len(numbers) - 1)]

gcd = math.gcd(*diff_list)
ans = set()

for i in range(1, math.ceil(gcd ** (1 / 2)) + 1):
    if gcd % i == 0:
        ans.add(i)
        ans.add(gcd // i)

ans.remove(1)
print(*sorted(list(ans)))
