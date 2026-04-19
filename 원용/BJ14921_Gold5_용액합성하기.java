package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ14921_Gold5_용액합성하기 {
    /*
    * 투 포인터 사용해서 양 끝 쪽을 더하면서 중앙으로 이동
    *   if 양수 -> 우측--
    *      음수 -> 좌측++
    *
    * + 0과 가까운 수를 구할 때, 절대값으로 비교해야 해야 함
    * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0;
        int end = nums.length - 1;

        int answer = Integer.MAX_VALUE;
        while (start < end) {
            int temp = nums[start] + nums[end];

            if (Math.abs(answer) > Math.abs(temp)) answer = temp;
            if (temp > 0) end--;
            else start++;
        }

        System.out.println(answer);
    }
}
