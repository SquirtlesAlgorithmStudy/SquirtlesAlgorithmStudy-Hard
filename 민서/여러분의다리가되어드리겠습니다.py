import sys;sys.setrecursionlimit(1<<30)
input = open(0).readline
def main():
    N = int(input())
    parent = [-1] * (N + 1)
    def find(x):
        if parent[x] < 0: return x
        parent[x] = find(parent[x])
        return parent[x]
    def union(x, y):
        x, y = find(x), find(y)
        if x == y: return False
        if parent[x] < parent[y]: x, y = y, x
        parent[y] += parent[x]
        parent[x] = y
        return True
    for _ in range(N - 2):
        x, y = map(int, input().split())
        union(x, y)
    root = find(1)
    for i in range(2, N + 1):
        if find(i) != root:
            print(1, i)
            return
main()
