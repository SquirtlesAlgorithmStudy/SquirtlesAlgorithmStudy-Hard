import sys

input = sys.stdin.readline


class SegTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [1] * (4 * self.n)
        self.build(arr, 1, 0, self.n - 1)

    def build(self, arr, node, start, end):
        if start == end:
            value = arr[start]
            if value > 0:
                self.tree[node] = 1
            elif value < 0:
                self.tree[node] = -1
            else:
                self.tree[node] = 0

        else:
            mid = (start + end) // 2
            self.build(arr, 2 * node, start, mid)
            self.build(arr, 2 * node + 1, mid + 1, end)
            self.tree[node] = self.tree[2 * node] * self.tree[2 * node + 1]

    def update(self, node, start, end, idx, val):
        if start == end:
            if val > 0:
                self.tree[node] = 1
            elif val < 0:
                self.tree[node] = -1
            else:
                self.tree[node] = 0

        else:
            mid = (start + end) // 2
            if idx <= mid:
                self.update(2 * node, start, mid, idx, val)
            else:
                self.update(2 * node + 1, mid + 1, end, idx, val)
            self.tree[node] = self.tree[2 * node] * self.tree[2 * node + 1]

    def query(self, node, start, end, l, r):
        if r < start or end < l:
            return 1
        if l <= start and end <= r:
            return self.tree[node]

        mid = (start + end) // 2
        left = self.query(2 * node, start, mid, l, r)
        right = self.query(2 * node + 1, mid + 1, end, l, r)
        return left * right

    def update_val(self, idx, val):
        self.update(1, 0, self.n - 1, idx, val)

    def range_mul(self, l, r):
        return self.query(1, 0, self.n - 1, l, r)


def main():
    ans = []

    while True:
        try:
            N, K = map(int, input().split())
            X = list(map(int, input().split()))
            commands = [tuple(input().split()) for _ in range(K)]

            ans_string = ""
            tree = SegTree(X)

            for cmd in commands:
                if cmd[0] == "C":
                    tree.update_val(int(cmd[1]) - 1, int(cmd[2]))
                else:
                    res = tree.range_mul(int(cmd[1]) - 1, int(cmd[2]) - 1)
                    if res == 1:
                        ans_string += "+"
                    elif res == -1:
                        ans_string += "-"
                    else:
                        ans_string += "0"

            ans.append(ans_string)

        except:
            break
    for a in ans:
        print(a)


main()
