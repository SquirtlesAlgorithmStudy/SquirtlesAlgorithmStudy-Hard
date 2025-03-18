import bisect


class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        ret = 0
        heaters.sort()
        for h in houses:
            val = float("inf")
            idx = bisect.bisect_left(heaters, h)
            if idx != len(heaters):
                val = abs(heaters[idx] - h)

            if idx - 1 != -1:
                val = min(val, abs(heaters[idx - 1] - h))

            ret = max(ret, val)

        return ret
