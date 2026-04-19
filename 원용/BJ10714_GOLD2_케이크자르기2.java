package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ10714_GOLD2_케이크자르기2 {

    class Main {

        private static long[][] dp;
        private static int n;

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            n = Integer.parseInt(br.readLine());
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(br.readLine());
            }

            long answer = -1;
            dp = new long[n][n];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[j][k] = -1;
                }
            }

            for (int i = 0; i < n; i++) {
                answer = Math.max(solve((n - 1 + i) % n, (i + 1) % n, 1, nums) + nums[i], answer);
            }

            System.out.println(answer);
        }

        private static long solve(int l, int r, int flag, int[] nums) {
            if (dp[l][r] != -1) return dp[l][r];
            if (l == r) {
                if (flag == 0) {
                    return nums[l];
                } else {
                    return 0;
                }
            }

            long temp;
            if (flag == 0) {
                temp = Math.max(solve((n - 1 + l) % n, r, (flag + 1) % 2, nums) + nums[l], solve(l, (r + 1) % n, (flag + 1) % 2, nums) + nums[r]);
            } else {
                if (nums[l] > nums[r]) {
                    temp = solve((n - 1 + l) % n, r, (flag + 1) % 2, nums);
                } else {
                    temp = solve(l, (r + 1) % n, (flag + 1) % 2, nums);
                }
            }

            dp[l][r] = temp;
            return temp;
        }
    }
}
