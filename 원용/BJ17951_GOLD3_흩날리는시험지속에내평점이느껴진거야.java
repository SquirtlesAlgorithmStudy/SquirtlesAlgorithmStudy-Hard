package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ17951_GOLD3_흩날리는시험지속에내평점이느껴진거야 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0;
        int end = 2_000_000;

        int answer = Integer.MIN_VALUE;
        while (start <= end) {
            int mid = (start + end) / 2;

            int temp = 0;
            int group = 0;
            int min = Integer.MAX_VALUE;
            for (int num : nums) {
                temp += num;
                if (temp >= mid) {
                    group++;
                    min = Math.min(min, temp);
                    temp = 0;
                }
            }
            if (group == k) {
                answer = Math.max(answer, min);
            }

            // 최대로 나올 수 있는 점수가 나와야 하기 때문에 group == k일 땐 점수 시작점을 늘린다.
            if (group < k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        System.out.println(answer);
    }
}
