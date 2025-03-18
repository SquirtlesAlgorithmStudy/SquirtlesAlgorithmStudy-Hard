class Solution:
    def heater_ranges(self, heaters, radius):
        ranges = []
        for h in heaters:
            s, e = h - radius, h + radius
            if ranges and ranges[-1][1] >= s:
                s, _ = ranges.pop()
            ranges.append((s, e))
        return ranges
    def is_cover(self, houses, heaters, radius):
        ranges = self.heater_ranges(heaters, radius)
        i = 0
        for h in houses:
            while h > ranges[i][1]:
                i += 1
                if i == len(ranges):
                    return False
            if h < ranges[i][0]:
                return False
        return True
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses = sorted(houses)
        heaters = sorted(heaters)
        lo, hi = 0, 1_000_000_000
        while lo < hi:
            mid = (lo + hi) // 2
            if self.is_cover(houses, heaters, mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
