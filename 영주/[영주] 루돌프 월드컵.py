from itertools import permutations

f = list(map(int, input().split()))

total = 0
success = 0

for perm in permutations(range(4)):
    match = []

    for i in range(4):
        for j in range(i + 1, 4):
            fi = f[perm[i]]
            fj = f[perm[j]]

            win_i = (5 * fi) / (5 * fi + 5 * fj)
            win_j = (5 * fj) / (5 * fi + 5 * fj)
            d = (fi + fj) / (5 * fi + 5 * fj)

            match.append((win_i, win_j, d, i, j))

    for outcomes in permutations(match):
        scores = [0] * 4

        for outcome in outcomes:
            win_i, win_j, d, i, j = outcome
            scores[i] += 3 * win_i
            scores[j] += 3 * win_j
            scores[i] += d
            scores[j] += d

        s = sorted(enumerate(scores), key=lambda x: (-x[1], x[0]))
        if s[0][0] == perm[0] or s[1][0] == perm[0]:
            success += 1

        total += 1

result = round((success / total) * 100, 3)
print(result)
