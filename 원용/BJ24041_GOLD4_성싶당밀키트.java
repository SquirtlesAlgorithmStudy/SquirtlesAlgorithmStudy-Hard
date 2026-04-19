package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BJ24041_GOLD4_성싶당밀키트 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int g = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] nums = new int[n][];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            int s = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int o = Integer.parseInt(st.nextToken());

            nums[i] = new int[]{s, l, o};
        }

        long start = 1;
        long end = 2_000_000_000;

        while (start <= end) {
            long mid = (start + end) / 2;

            // 세균이 많은 상품을 기준으로 정렬한다.
            Arrays.sort(nums, (n1, n2) -> {
                long num1 = n1[0] * Math.max(1, mid - n1[1]);
                long num2 = n2[0] * Math.max(1, mid - n2[1]);
                return Long.compare(num2, num1);
            });

            long temp = 0;
            int count = k;
            for (int i = 0; i < n; i++) {
                if (nums[i][2] == 1 && count > 0) {
                    count--;
                    continue;
                }
                temp += nums[i][0] * Math.max(1, mid - nums[i][1]);
            }

            if (temp <= g) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        System.out.println(end);
    }
}
https://www.acmicpc.net/problem/2560