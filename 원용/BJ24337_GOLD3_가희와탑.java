package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BJ24337_GOLD3_가희와탑 {

    class Main {

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());

            int k = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (a + b > k + 1) {
                System.out.println(-1);
                return;
            }

            solve(a, b, k);

//        for (int i = 1; i <= k; i++) {
//            for (int j = 1; j <= k - i + 1; j++) {
//                System.out.print("a : " + i + " , b: " + j + " : ");
//                solve(i, j, k);
//                System.out.print(" vs ");
//                answer(i, j, k);
//                System.out.println();
//            }
//        }

            br.close();
        }

        private static void solve(int a, int b, int k) throws IOException {
            StringBuilder sb = new StringBuilder();
            int[] nums = new int[k];

            // 최대 건물 크기
            int max = Math.max(a, b);

            int mid;
            if (a == 1 || a > k - b) {
                mid = a - 1;
            } else {
                mid = k - b;
            }
            nums[mid] = max;

            int left = 1;
            int count = 1;
            for (int i = 0; i < mid; i++) {
                nums[i] = left;
                count++;
                if (mid - i >= a) {
                    left = 1;
                } else {
                    left += 1;
                }
            }

            int right = 1;
            count = 1;
            for (int i = k - 1; i > mid; i--) {
                nums[i] = right;
                count++;
                if (count >= max) {
                    right = 1;
                } else {
                    right += 1;
                }
            }

            for (int n : nums) {
                sb.append(n).append(" ");
            }

            System.out.println(sb);
        }

        // 타 블로그 정답
        private static void answer(int a, int b, int n) {
            ArrayList<Integer> tower = new ArrayList<>();

            if (a + b > n + 1) {
                System.out.print(-1);
                return;
            }

            for (int i = 1; i < a; i++) {
                tower.add(i);
            }
            tower.add(Math.max(a, b));

            for (int i = b - 1; i >= 1; i--) {
                tower.add(i);
            }

            if (a == 1) {
                while (tower.size() < n) {
                    tower.add(1, 1);
                }
            } else {
                while (tower.size() < n) {
                    tower.add(0, 1);
                }
            }
            for (int i : tower) {
                System.out.print(i + " ");
            }
        }
    }

}
