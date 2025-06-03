package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ14908_GOLD1_구두수선공 {

    // solve: https://www.acmicpc.net/source/95022648
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        // 0: idx , 1: 작업일 , 2: 보상금
        PriorityQueue<int[]> que = new PriorityQueue<>((w1, w2) -> {
            int me = w1[1] * w2[2];     // 내 작업일 * 다른 사람 보상일 <- 내가 먼저 일을 하면 발생하는 지연금
            int other = w2[1] * w1[2];  // 다른 사람 작업일 * 내 보상금 <- 상대방이 먼저 일을 하면 발생하는 지연금

            if (me == other) return w1[0] - w2[0];

            // 둘 중 지연금이 더 큰 쪽이 먼저 일을 해야함
            return me - other;
        });

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            que.add(new int[]{i + 1, t, s});
        }

        StringBuilder sb = new StringBuilder();
        while (!que.isEmpty()) {
            int[] nums = que.poll();

            sb.append(nums[0]).append(" ");
        }
        System.out.println(sb);
    }
}
