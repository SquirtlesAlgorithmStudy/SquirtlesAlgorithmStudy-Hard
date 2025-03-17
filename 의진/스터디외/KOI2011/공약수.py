import sys
import math

input = sys.stdin.readline

N, M = map(int, input().split())

i = 2
while True:
    if i * i > M // N:
        break
    i += 1

while True:
    if (M // N) % i == 0 and math.gcd(i, (M // N) // i) == 1:
        break

    i -= 1

print(" ".join(map(str, sorted([N * i, M // i]))))
