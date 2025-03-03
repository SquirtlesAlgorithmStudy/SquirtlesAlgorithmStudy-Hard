class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        slot = [float("inf"), float("inf")]

        for num in nums:
            flag = True
            for i, s in enumerate(slot):
                if s >= num:
                    slot[i] = num
                    flag = False
                    break
            if flag:
                return True

        return False


class Solution:
    def increasingTriplet(self, nums):
        INF = float("inf")
        first = INF
        second = INF
        for n in nums:
            if n <= first:
                first = n
            elif n <= second:
                second = n
            else:
                return True
        return False
