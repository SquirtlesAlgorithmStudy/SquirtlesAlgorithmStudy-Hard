package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BJ16986_GOLD2_인싸들의가위바위보 {

    // 경희, 민호가 낼 손동작
    static Map<String, int[]> p = new HashMap<>();
    // 경희, 민호가 낼 손동작 index
    static Map<String, Integer> pIdx = new HashMap<>();
    // 지우, 경희, 민호 이긴 경기 수
    static Map<String, Integer> pw = new HashMap<>();

    static Map<Integer, Set<Integer>> comb = new HashMap<>();
    static boolean[] visited;
    static int k;
    static int n;
    static boolean answer = false;

    /*
     * 무승부 일 땐 항상 민호 > 경희 > 지우 순으로 이긴다. (지우 , 경희, 민호 순으로 시작했기 때문에 무승부 결과는 고정된다.)
     * 무승부도 유동적으로 하다가 2시간 날렸다.
     *
     *
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            comb.put(i, new HashSet<>());
        }

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 1; j <= n; j++) {
                int num = Integer.parseInt(st.nextToken());

                if (num == 2) {
                    comb.get(i).add(j);
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        int[] kh = new int[20];
        for (int i = 0; i < 20; i++) {
            kh[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        int[] mh = new int[20];
        for (int i = 0; i < 20; i++) {
            mh[i] = Integer.parseInt(st.nextToken());
        }

        p.put("kh", kh);
        p.put("mh", mh);
        pIdx.put("kh", 0);
        pIdx.put("mh", 0);
        pw.put("jw", 0);
        pw.put("kh", 0);
        pw.put("mh", 0);

        dfs("jw", "kh", "mh");

        if (answer) System.out.println(1);
        else System.out.println(0);
    }

    static void dfs(
            String first,
            String second,
            String next
    ) {
        if (answer) return;

        // 지우가 승리 조건을 만족했을 때
        if (pw.get("jw") == k) {
            answer = true;
            return;
        }

        // 다른 사람이 먼저 승리 조건을 만족했다면 return 한다.
        if (pw.get("kh") == k || pw.get("mh") == k) return;

        // 현재 지우가 낸 손동작을 계산한다.
        boolean isAllUse = true;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            isAllUse = false;
            break;
        }
        // 아직 승리 조건을 만족하지 않았는데, 모든 손동작을 낸 상태면, 다음부터 중복된 손동작을 내야하니까 return 한다.
        if (isAllUse) {
            return;
        }

        if (!first.equals("jw") && !second.equals("jw")) {
            int fIdx = pIdx.get(first);
            int sIdx = pIdx.get(second);

            if (fIdx >= 20 || sIdx >= 20) return;

            int f = p.get(first)[fIdx];
            int s = p.get(second)[sIdx];
            pIdx.put(first, pIdx.get(first) + 1);
            pIdx.put(second, pIdx.get(second) + 1);

            if (comb.get(f).contains(s)) {
                pw.put(first, pw.get(first) + 1);
                dfs(first, next, second);
                pw.put(first, pw.get(first) - 1);
            } else if(comb.get(s).contains(f)) {
                pw.put(second, pw.get(second) + 1);
                dfs(second, next, first);
                pw.put(second, pw.get(second) - 1);
            } else { // 무승부일 경우
                if (first.equals("mh")){
                    pw.put(first, pw.get(first) + 1);
                    dfs(first, next, second);
                    pw.put(first, pw.get(first) - 1);
                } else {
                    pw.put(second, pw.get(second) + 1);
                    dfs(second, next, first);
                    pw.put(second, pw.get(second) - 1);
                }
            }
            pIdx.put(first, pIdx.get(first) - 1);
            pIdx.put(second, pIdx.get(second) - 1);

            return;
        }

        // 지우가 선공일 때
        if (first.equals("jw")) {
            int sIdx = pIdx.get(second);
            if (sIdx >= 20) return;

            int s = p.get(second)[sIdx];

            pIdx.put(second, pIdx.get(second) + 1);
            for (int i = 1; i <= n; i++) {
                if (visited[i]) continue;

                visited[i] = true;

                // 지우가 이기는 경우
                if (comb.get(i).contains(s)) {
                    pw.put(first, pw.get(first) + 1);
                    dfs("jw", next, second);
                    pw.put(first, pw.get(first) - 1);
                } else {
                    // 지우가 지는 경우
                    pw.put(second, pw.get(second) + 1);
                    dfs(second, next, "jw");
                    pw.put(second, pw.get(second) - 1);
                }

                visited[i] = false;
            }

            pIdx.put(second, pIdx.get(second) - 1);
            return;
        }

        // 지우가 후공일 때
        if (second.equals("jw")) {
            int fIdx = pIdx.get(first);
            if (fIdx >= 20) return;

            int f = p.get(first)[fIdx];
            pIdx.put(first, pIdx.get(first) + 1);
            for (int i = 1; i <= n; i++) {
                if (visited[i]) continue;

                visited[i] = true;

                if (comb.get(i).contains(f)) {
                    // 지우가 이기는 경우
                    pw.put(second, pw.get(second) + 1);
                    dfs(second, next, first);
                    pw.put(second, pw.get(second) - 1);
                } else {
                    // 지우가 지는 경우
                    pw.put(first, pw.get(first) + 1);
                    dfs(first, next, second);
                    pw.put(first, pw.get(first) - 1);
                }

                visited[i] = false;
            }

            pIdx.put(first, pIdx.get(first) - 1);
        }
    }
}
