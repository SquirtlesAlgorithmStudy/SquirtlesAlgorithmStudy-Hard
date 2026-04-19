package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ15989_GOLD5_123더하기4 {
    /*
     *
     * 1 2 3 4 5 6 7  8  9 10 11 12 13 14 15
     * 1 2 3 4 5 7 8 10 12 14 16 19 21 24 27
     *
     * n = n-1 + (무언가) 인 것은 알았다.
     * (무언가)를 어떻게 구하지 하다가, 평소엔 n-2 - n-3 을 합하다가 3의 배수 일 때만 1을 더하는 규칙을 발견
     * 그래서 아래와 같이 했더니 맞았다.
     *
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        int[] nums = new int[t];
        for(int i = 0 ; i < t ; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }

        int[] dp = new int[10_001];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for(int i = 4 ; i <= 10_000 ; i++) {
            int temp = dp[i-1] + (dp[i-2] - dp[i-3]);
            if(i % 3 == 0) temp += 1;

            dp[i] = temp;
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0 ; i < t ; i++) {
            sb.append(dp[nums[i]]).append("\n");
        }

        System.out.println(sb);
    }
}
