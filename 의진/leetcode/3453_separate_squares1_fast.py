class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        e = []
        s = 0
        for x, y, l in squares:
            e.extend([(y, 1, l), (y + l, -1, l)])
            s += l * l

        e.sort()
        t = s / 2
        c = 0
        p = e[0][0]
        a = 0

        for y, d, l in e:
            h = y - p
            if h:
                a += c * h
                if a >= t:
                    return p + (t - (a - c * h)) / c
            c += d * l
            p = y

        return p
