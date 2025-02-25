class Solution:
    def maxArea(self, height: List[int]) -> int:
        start = 0
        end = len(height) - 1
        result = 0

        while start < end:
            result = max(result, min(height[start], height[end]) * (end - start))

            if height[start] <= height[end]:
                pivot = height[start]
                while height[start] <= pivot and start != end:
                    start += 1

            else:
                pivot = height[end]
                while height[end] <= pivot and start != end:
                    end -= 1

        return result
