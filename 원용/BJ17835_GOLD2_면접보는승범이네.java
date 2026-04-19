package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BJ17835_GOLD2_면접보는승범이네 {
    class Main {
        /*
         * 면접장에서부터 다익스트라를 진행한다.
         * */
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            // 0: 도착 도시, 1: 거리
            Map<Integer, List<int[]>> graph = new HashMap<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                List<int[]> values = graph.computeIfAbsent(v, key -> new ArrayList<>());
                values.add(new int[]{u, c});
            }

            Set<Integer> city = new HashSet<>();
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < k; i++) {
                city.add(Integer.parseInt(st.nextToken()));
            }

            long[] dist = new long[n + 1];
            for (int j = 1; j <= n; j++) {
                dist[j] = Long.MAX_VALUE;
            }

            // 0: 시작 도시, 1: 거리
            PriorityQueue<long[]> pq = new PriorityQueue<>((p1, p2) -> (int) (p1[1] - p2[1]));
            for (int c : city) {
                pq.add(new long[]{c, 0});
            }

            boolean[] visited = new boolean[n + 1];
            while (!pq.isEmpty()) {
                long[] node = pq.poll();
                long s = node[0];
                long curr = node[1];

                if (!graph.containsKey((int) (s)) || visited[(int) (s)]) continue;
                visited[(int) (s)] = true;

                for (int[] c : graph.get((int) (s))) {
                    int e = c[0];
                    int d = c[1];
                    if (city.contains(e) || visited[e] || curr + d > dist[e]) continue;
                    pq.add(new long[]{e, curr + d});
                    dist[e] = curr + d;
                }
            }

            int maxCity = 0;
            long maxDist = 0;
            for (int i = 1; i <= n; i++) {
                if (dist[i] == Long.MAX_VALUE || maxDist >= dist[i]) continue;
                maxDist = dist[i];
                maxCity = i;
            }
            StringBuilder sb = new StringBuilder();
            sb.append(maxCity).append("\n").append(maxDist);
            System.out.println(sb);
        }
    }
}
