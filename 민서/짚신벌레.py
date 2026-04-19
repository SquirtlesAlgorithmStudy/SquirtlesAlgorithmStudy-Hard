input = open(0).readline
a, b, d, N = map(int, input().split())
b, c = b - a, d - b
baby, adult, old = [0] * a, [0] * b, [0] * c
baby[0] = 1
n_baby, n_adult, n_old = 1, 0, 0
baby_idx, adult_idx, old_idx = 0, 0, 0
for _ in range(N):
    baby_idx = (baby_idx + 1) % a
    adult_idx = (adult_idx + 1) % b
    old_idx = (old_idx + 1) % c
    n_old -= old[old_idx]
    n_old += adult[adult_idx]
    n_old %= 1000
    n_adult -= adult[adult_idx]
    old[old_idx] = adult[adult_idx]
    n_adult += baby[baby_idx]
    n_adult %= 1000
    n_baby -= baby[baby_idx]
    adult[adult_idx] = baby[baby_idx]
    n_baby += n_adult
    n_baby %= 1000
    baby[baby_idx] = n_adult
print((n_baby + n_adult + n_old) % 1000)

###############################################
from collections import deque
input = open(0).readline
a, b, d, N = map(int, input().split())
b, c = b - a, d - b
baby, adult, old = deque([1]), deque(), deque()
n_baby, n_adult, n_old = 1, 0, 0
for _ in range(N):
    if len(old) == c:
        n_old -= old.popleft()
        n_old %= 1000
    if len(adult) == b:
        tmp = adult.popleft()
        n_adult -= tmp
        n_adult %= 1000
        old.append(tmp)
        n_old += tmp
        n_adult %= 1000
    if len(baby) == a:
        tmp = baby.popleft()
        n_baby -= tmp
        n_baby %= 1000
        adult.append(tmp)
        n_adult += tmp
        n_adult %= 1000
    baby.append(n_adult)
    n_baby += n_adult
    n_baby %= 1000
print((n_baby + n_adult + n_old) % 1000)
