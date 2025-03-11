class Solution:
    def get2Area(self, x, y, l, th):
        if y >= th:
            return l * l, 0
        elif y + l <= th:
            return 0, l * l
        else:
            return l * (y + l - th), l * (th - y)
    def total2Area(self, squares, th):
        up, down = 0, 0
        for x, y, l in squares:
            u, d = self.get2Area(x, y, l, th)
            up += u
            down += d
        return up, down
    def separateSquares(self, squares: List[List[int]]) -> float:
        lo, hi = 0, 2 * (10 ** 9)
        while lo + 10 ** -5 < hi:
            mid = (lo + hi) / 2
            up, down = self.total2Area(squares, mid)
            if up > down:
                lo = mid
            else:
                hi = mid
        return lo
