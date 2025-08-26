N, X = map(int, input().split())
bur = [1] * 51
pat = [1] * 51

for i in range(1, N + 1):
    bur[i] = 2 * bur[i - 1] + 3
    pat[i] = 2 * pat[i - 1] + 1


def eat(n, x):
    if n == 0:
        return x  # x = 0이면 0, 1이면 1
    if x == 1:  # 왼쪽 빵
        return 0
    if x <= 1 + bur[n - 1]:  # 왼쪽
        return eat(n - 1, x - 1)
    if x == 1 + bur[n - 1] + 1:  # 패티
        return pat[n - 1] + 1
    if x <= bur[n - 1] + bur[n - 1] + 1 + 1:  # 오른쪽
        return pat[n - 1] + 1 + eat(n - 1, (x - (bur[n - 1] + 2)))

    return pat[n]  # 오른쪽 빵


print(eat(N, X))
