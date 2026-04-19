package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class BJ18235_GOLD3_지금만나러갑니다 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        Queue<int[]> que = new ArrayDeque<>();
        que.add(new int[]{a, 0});
        que.add(new int[]{b, 0});
        // 최대 요일 : log2(500_000) => 19
        boolean[][] visited = new boolean[21][500_001];

        int answer = -1;
        while (!que.isEmpty()) {
            int[] nums = que.poll();
            int num = nums[0];
            int dep = nums[1];

            int div = (int) Math.pow(2, dep);

            int right = num + div;
            if (right <= n) {
                if(visited[dep+1][right]) {
                    answer = dep + 1;
                    break;
                }
                visited[dep+1][right] = true;
                que.add(new int[]{right, dep+1});
            }

            int left = num - div;
            if (left >= 1) {
                if(visited[dep+1][left]) {
                    answer = dep + 1;
                    break;
                }
                visited[dep+1][left] = true;
                que.add(new int[]{left, dep+1});
            }
        }

        System.out.println(answer);
    }
}
