package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ11058_GOLD5_크리보드 {

    class Main {
        /*
         *
         * 아래 조건을 순회하면서 최대 값을 구한다.
         *  1. 이전 값에서 A만 출력하는 경우 (nums[i] + 1)
         *  2. 복붙을 연속으로 하는 경우
         *
         * */
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());

            if (n <= 6) {
                System.out.println(n);
                return;
            }

            long[] nums = new long[n + 1];
            for (int i = 0; i <= 6; i++) {
                nums[i] = i;
            }

            for (int i = 7; i <= n; i++) {
                nums[i] = nums[i - 1] + 1;
                for (int j = 3; j <= i; j++) {
                    nums[i] = Math.max(nums[i - j] * (j - 1), nums[i]);
                }
            }

            System.out.println(nums[n]);
        }
    }

}
