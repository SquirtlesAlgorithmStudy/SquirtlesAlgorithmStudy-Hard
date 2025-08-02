package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ17352_GOLD5_여러분의다리가되어드리겠습니다 {

    class Main {

        /*
         *
         * 결국에 부모가 다른 것이 2개가 나올 것이다.
         * 그 부모 노드 2개를 출력하자.
         *
         * */
        private static int[] parent;

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());

            parent = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }

            for (int i = 0; i < n - 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());

                int sp = getParent(s);
                int ep = getParent(e);

                if (sp != ep) union(sp, ep);
            }

            int a1 = getParent(1);
            StringBuilder sb = new StringBuilder();
            sb.append(a1).append(" ");
            for (int i = 2; i <= n; i++) {
                if (a1 == getParent(i)) continue;
                sb.append(parent[i]);
                break;
            }

            System.out.println(sb);
        }

        private static int getParent(int c) {
            if (c == parent[c]) return parent[c];
            return parent[c] = getParent(parent[c]);
        }

        private static void union(int s, int e) {
            if (s >= e) {
                parent[s] = e;
            } else {
                parent[e] = s;
            }
        }
    }
}
