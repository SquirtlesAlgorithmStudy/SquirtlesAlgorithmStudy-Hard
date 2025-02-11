class Solution:
    def jump(self, nums: List[int]) -> int:
        arr = [num + i for i, num in enumerate(nums)]
        pointer = 0
        jump = 0

        while pointer < len(nums) - 1:
            if arr[pointer] >= len(nums) - 1:
                jump += 1
                break

            value = max(
                enumerate(arr[pointer + 1 : min(len(nums), arr[pointer] + 1)]),
                key=lambda x: x[1],
            )
            pointer = value[0] + 1 + pointer
            jump += 1

        return jump
