import sys

input = sys.stdin.readline

N, M = map(int, input().split())
coords = [tuple(map(int, input().split())) for _ in range(N)]
connections = set(tuple(map(int, input().split())) for _ in range(M))

costs = [[-1] * (N + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if i == j:
            costs[i][j] = 0
            continue
        if i > j:
            costs[i][j] = costs[j][i]
            continue

        if (i, j) in connections or (j, i) in connections:
            costs[i][j] = 0
            continue

        costs[i][j] = (
            (coords[i - 1][0] - coords[j - 1][0]) ** 2
            + (coords[i - 1][1] - coords[j - 1][1]) ** 2
        ) ** (1 / 2)


def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]


def union(parent, rank, x, y):
    px, py = find(parent, x), find(parent, y)
    if px == py:
        return False
    if rank[px] < rank[py]:
        px, py = py, px
    parent[py] = px
    if rank[px] == rank[py]:
        rank[px] += 1
    return True


edges = []
for i in range(1, N + 1):
    for j in range(i + 1, N + 1):
        edges.append((costs[i][j], i, j))

edges.sort()

parent = list(range(N + 1))
rank = [0] * (N + 1)
total_cost = 0
edge_count = 0

for cost, u, v in edges:
    if union(parent, rank, u, v):
        total_cost += cost
        edge_count += 1
        if edge_count == N - 1:
            break

print(f"{total_cost:.2f}")
