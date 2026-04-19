package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ3649_GOLD5_로봇프로젝트 {
    private static int NANO = 10_000_000;

    public static void main(String[] args) throws IOException {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            while (true) {
                int x = Integer.parseInt(br.readLine()) * NANO;
                int n = Integer.parseInt(br.readLine());

                int[] nums = new int[n];
                for (int i = 0; i < n; i++) {
                    nums[i] = Integer.parseInt(br.readLine());
                }

                int left = 0;
                int right = nums.length - 1;
                Arrays.sort(nums);
                boolean isAns = false;
                while (left < right) {
                    int temp = nums[left] + nums[right];
                    if (temp == x) {
                        isAns = true;
                        break;
                    }
                    if (temp > x) {
                        right--;
                    } else {
                        left++;
                    }
                }

                if (isAns) System.out.println("yes " + nums[left] + " " + nums[right]);
                else System.out.println("danger");
            }
        } catch (Exception e) {

        }
    }
}
