class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1
        if n == 1:
            return 1

        idx_2 = 1
        idx_3 = 1
        idx_5 = 1

        for i in range(2, n + 1):
            min_val = min(2 * dp[idx_2], 3 * dp[idx_3], 5 * dp[idx_5])
            if min_val == 2 * dp[idx_2]:
                idx_2 += 1
            if min_val == 3 * dp[idx_3]:  # elseif 안됨
                idx_3 += 1
            if min_val == 5 * dp[idx_5]:
                idx_5 += 1
            dp[i] = min_val

        return dp[n]
