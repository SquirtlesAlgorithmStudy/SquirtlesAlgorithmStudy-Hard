class Solution:
    def jump(self, nums: List[int]) -> int:
        memo = [1<<30] * len(nums)
        memo[0] = 0
        for i, n in enumerate(nums):
            for j in range(i, min(i + n + 1, len(nums))):
                memo[j] = min(memo[j], memo[i] + 1)
        return memo[-1]


class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        memo = []
        start = 0
        end = min(nums[0], len(nums) - 1)
        memo.append(end)
        while end < len(nums) - 1:
            mx = max(i + nums[i] for i in range(start, end + 1))
            start, end = end + 1, mx
            memo.append(end)
        return len(memo)
