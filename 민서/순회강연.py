input = open(0).readline
def main():
    N = int(input())
    if N == 0:
        print(0)
        return
    arr = sorted(tuple(map(int, input().split())) for _ in range(N))
    parent = [-1] * (max([d for _, d in arr]) + 1)
    ans = 0
    def find(x):
        if parent[x] < 0:
            return x
        parent[x] = find(parent[x])
        return parent[x]
    for p, d in reversed(arr):
        d = find(d)
        if d == 0:
            continue
        ans += p
        parent[d] = d - 1
    print(ans)
main()
