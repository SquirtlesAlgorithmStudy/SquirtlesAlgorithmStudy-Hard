package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ15661_GOLD5_링크와스타트 {

    /*
     *
     * 1. (2 ~ N/2) 조합을 구한다.
     *      최대 : 20C10 = 184,756
     * 2. 각 팀의 합계를 구한다.
     *      최대 : 10 ^ 2
     * 3. 최소 값을 갱신한다
     * 10^7 쯤 되겠지 싶어서 모든 조합 구하기 + 2중 반복문으로 팀 합계 구하기
     * */
    private static int n;
    private static int[][] nums;
    private static int answer = Integer.MAX_VALUE;
    private static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        nums = new int[n][n];
        visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                nums[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 2; i <= n / 2; i++) {
            comb(0, 0, i);
        }
        System.out.println(answer);
    }

    private static void comb(int startIdx, int idx, int max) {
        if (idx == max) {
            int[] start = new int[max];
            int[] link = new int[n - max];
            int sIdx = 0;
            int lIdx = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    start[sIdx++] = i;
                } else {
                    link[lIdx++] = i;
                }
            }

            int s = 0;
            for (int i = 0; i < max; i++) {
                for (int j = i + 1; j < max; j++) {
                    s += nums[start[i]][start[j]] + nums[start[j]][start[i]];
                }
            }

            int l = 0;
            for (int i = 0; i < n - max; i++) {
                for (int j = i + 1; j < n - max; j++) {
                    l += nums[link[i]][link[j]] + nums[link[j]][link[i]];
                }
            }

            answer = Math.min(answer, Math.abs(s - l));

            return;
        }

        for (int i = startIdx; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            comb(i + 1, idx + 1, max);
            visited[i] = false;
        }
    }
}
