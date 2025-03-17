import sys

input = sys.stdin.readline

M, N, L = map(int, input().split())
gun = list(map(int, input().split()))
animals = [tuple(map(int, input().split())) for _ in range(N)]

gun.sort()
animals.sort()

animal_idx = 0
gun_idx = 0
cnt = 0

while animal_idx < len(animals) and gun_idx < len(gun) + 1:
    now_gun = gun[gun_idx]
    if gun_idx + 1 < len(gun):
        next_gun = gun[gun_idx + 1]
        bound = (now_gun + next_gun) / 2
    else:
        bound = float("inf")

    now_ani = animals[animal_idx]

    if now_ani[0] > bound:
        gun_idx += 1
        continue

    if abs(now_ani[0] - now_gun) + now_ani[1] <= L:
        cnt += 1
    animal_idx += 1

print(cnt)
