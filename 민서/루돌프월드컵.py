import itertools
input = open(0).readline
score = [0, 1, 3]
vs = [(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)]
vs_inv = {(0, 1): 0, (0, 2): 1, (0, 3): 2, (1, 2): 3, (1, 3): 4, (2, 3): 5}
F = [*map(int, input().split())]
ans = 0
for status in itertools.product([0, 1, 2], repeat=6):
    scores = [0] * 4
    prob = 1.0
    for (a, b), s in zip(vs, status):
        scores[a] += score[s]
        scores[b] += score[2 - s]
        div = 5 * F[a] + 5 * F[b]
        prob *= [4 * F[b] / div, (F[a] + F[b]) / div, 4 * F[a] / div][s]
    scores = [(s, 3 - i) for i, s in enumerate(scores)]
    scores = sorted(scores)
    if scores[2][1] == 3 or scores[3][1] == 3:
        ans += prob
print(f"{ans * 100:.3f}")
