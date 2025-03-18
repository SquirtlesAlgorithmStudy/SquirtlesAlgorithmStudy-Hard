class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        if len(heaters) == 1:
            ret = 0
            for house in houses:
                ret = max(ret, abs(house - heaters[0]))
            return ret

        heaters.sort()
        heaters.extend([float("inf")])
        houses.sort()

        heater_idx = 0
        house_idx = 0
        bound = (heaters[0] + heaters[1]) / 2

        ret = 0

        while house_idx < len(houses):
            if houses[house_idx] > bound:
                heater_idx += 1
                bound = (heaters[heater_idx] + heaters[heater_idx + 1]) / 2
                continue

            ret = max(ret, abs(houses[house_idx] - heaters[heater_idx]))
            house_idx += 1
        return ret
