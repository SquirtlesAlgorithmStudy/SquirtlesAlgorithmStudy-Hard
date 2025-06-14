package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ2560_GOLD3_짚신벌레 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[] nums = new int[n + 1];
        for (int i = 0; i < a; i++) {
            nums[i] = 1;
        }

        for (int i = a; i <= n; i++) {
            nums[i] = (nums[i - 1] + nums[i - a]) % 1000;

            if (i >= b) {
                nums[i] = (nums[i] - nums[i - b] + 1000) % 1000;
            }
        }

        int answer = nums[n];
        if (n >= d) {
            answer = (nums[n] - nums[n - d] + 1000) % 1000;
        }

        System.out.println(answer);
    }
}
