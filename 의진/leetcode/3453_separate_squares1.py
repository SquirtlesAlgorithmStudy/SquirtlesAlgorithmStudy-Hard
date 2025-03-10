# 1006ms
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        start = 0
        max_height_square = max(squares, key=lambda item: item[1] + item[2])
        end = max_height_square[1] + max_height_square[2]
        while start <= end:
            mid = (start + end) // 2
            if self._do_test(mid, squares):
                start = mid + 1
            else:
                end = mid - 1

        small_upper, big_lower = self._get_all_square_area(start, squares)
        big_upper, _ = self._get_all_square_area(end, squares)
        middle = (small_upper + big_lower) / 2

        return end + ((big_upper - middle) / (big_upper - small_upper))

    def _get_all_square_area(self, mid, squares):
        upper = 0
        lower = 0
        for sq in squares:
            if sq[1] <= mid <= sq[1] + sq[2]:
                upper += sq[2] * (sq[1] + sq[2] - mid)
                lower += sq[2] * (mid - sq[1])
                continue

            if sq[1] > mid:
                upper += sq[2] * sq[2]
            else:
                lower += sq[2] * sq[2]
        return upper, lower

    def _do_test(self, mid, squares):
        upper, lower = self._get_all_square_area(mid, squares)
        return upper > lower
