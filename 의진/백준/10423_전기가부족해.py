import sys

input = sys.stdin.readline


def main():
    N, M, K = map(int, input().split())
    plants = set(map(int, input().split()))

    connections = [tuple(map(int, input().split())) for _ in range(M)]

    return kruskal_mst_custom(N, connections, plants)


class UnionFind:
    def __init__(self, n, plant_nodes):
        self.parent = [0] * (n + 1)

        for i in range(1, n + 1):
            if i not in plant_nodes:
                self.parent[i] = i

    def find(self, x):
        if self.parent[x] == 0:
            return 0
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if root_x < root_y:
                self.parent[root_y] = root_x
            else:
                self.parent[root_x] = root_y
            return True
        return False


def kruskal_mst_custom(n, edges, plant_nodes):
    uf = UnionFind(n, plant_nodes)
    sorted_edges = sorted(edges, key=lambda x: x[2])
    total_weight = 0

    for u, v, weight in sorted_edges:
        if uf.union(u, v):
            total_weight += weight

    return total_weight


print(main())
