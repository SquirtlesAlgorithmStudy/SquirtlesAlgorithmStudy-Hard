import bisect


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        seq = []
        for num in nums:
            if not seq or seq[-1] < num:
                seq.append(num)
            else:
                idx = bisect.bisect_left(seq, num)
                seq[idx] = num

            if len(seq) >= 3:
                return True

        return False
