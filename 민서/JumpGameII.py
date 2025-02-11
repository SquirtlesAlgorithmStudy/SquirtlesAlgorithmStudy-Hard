class Solution:
    def jump(self, nums: List[int]) -> int:
        memo = [1<<30] * len(nums)
        memo[0] = 0
        for i, n in enumerate(nums):
            for j in range(i, min(i + n + 1, len(nums))):
                memo[j] = min(memo[j], memo[i] + 1)
        return memo[-1]
