package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ2981_GOLD4_검문 {
    /*
     * N = a * M + r
     *
     * A1 = a1*M + r
     * A2 = a2*M + r
     *
     * (A1-A2) = (a1-a2)M
     *
     * M은 A1-A2의 약수이다.
     *
     * 따라서 연속된 값의 차를 구하고, 이들의 최대 공약수를 구한다음에
     * 최대 공약수의 약수들을 구하면 된다.
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(nums);
        int[] diff = new int[n-1];
        for (int i = 1; i < n; i++) {
            diff[i-1] = nums[i] - nums[i - 1];
        }

        int gcd = diff[0];
        for (int i = 1; i < n - 1; i++) {
            gcd = getGcd(gcd, diff[i]);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 2; i <= gcd ; i++) {
            if (gcd % i != 0) continue;
            sb.append(i).append(" ");
        }

        System.out.println(sb);
    }

    public static int getGcd(int a, int b) {
        int min = Math.min(a, b);
        int max = Math.max(a, b);

        while (max % min != 0) {
            int temp = min;
            min = max % min;
            max = temp;
        }

        return min;
    }
}
