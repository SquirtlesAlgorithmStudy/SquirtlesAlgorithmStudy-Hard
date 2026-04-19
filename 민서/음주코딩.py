import sys
input = open(0).readline
mapping = ["0", "+", "-"]
class Segtree:
    def __init__(self, N):
        L = 1
        while L < N:
            L <<= 1
        self.tree = [1] * (2 * L)
        self.L = L - 1
    def update(self, i, n):
        i += self.L
        self.tree[i] = n
        i >>= 1
        while i:
            self.tree[i] = self.tree[i<<1] * self.tree[(i<<1) + 1]
            i >>= 1
    def query(self, i, j):
        i, j = i + self.L, j + self.L
        ans = 1
        while i <= j:
            if i & 1:
                ans *= self.tree[i]
                i += 1
            i >>= 1
            if not j & 1:
                ans *= self.tree[j]
                j -= 1
            j >>= 1
        return ans
def testcase(N, K):
    tree = Segtree(N)
    for i, n in enumerate(map(int, input().split()), start=1):
        if n < 0:
            tree.update(i, -1)
        elif n == 0:
            tree.update(i, 0)
    for _ in range(K):
        c0, c1, c2 = input().split()
        c1, c2 = int(c1), int(c2)
        if c0 == "C":
            if c2 < 0:
                tree.update(c1, -1)
            elif c2 == 0:
                tree.update(c1, 0)
            else:
                tree.update(c1, 1)
        if c0 == "P":
            sys.stdout.write(mapping[tree.query(c1, c2)])
    sys.stdout.write("\n")
def main():
    while True:
        line = input()
        if not line:
            break
        N, K = map(int, line.split())
        testcase(N, K)
main()
