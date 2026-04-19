package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BJ10423_GOLD3_전기가부족해 {

    class Main {

        // 15: 30 ~ 16:30
        /*
         *
         * union find로 각 건물의 발전소를 나타낸다.
         *
         * sol 1 (실패)
         *   설치 비용을 기준으로 오름차순으로 나오는 pq에 노드들을 넣는다.
         *   하나씩 poll 하면서 발전소를 연결한다.
         *     1. 두 건물에 연결된 발전소가 없는 경우 -> 두 노드 연결 , 둘 중 아무나 노드 연결
         *     2. 두 건물 모두 발전소가 있는 경우 -> skip
         *     3. 하나의 건물에만 발전소가 있는 경우 -> 두 노드 연결 , 발전소 노드를 부모로 연결
         *   반례
         *      5 5 1
         *      1
         *      1 2 9
         *      2 3 1
         *      3 4 1
         *      4 5 1
         *      5 2 1
         *
         *      출력 : 13
         *
         *      맞는답 : 12
         *
         * so1 2 (시도)
         *   그래프로 노드들을 입력받는다.
         *   설치 비용을 기준으로 오름차순으로 나오는 pq에 발전소와 연결된 노드들을 넣는다.
         *
         *   pq를 순회하면서 아래를 재진행 한다.
         *     1. 하나의 건물에만 발전소가 있는 경우 -> 두 노드 연결 , 케이블 수++
         *     2. 두 건물 모두 발전소가 있는 경우 -> skip
         *     에외) 두 건물에 연결된 발전소가 없는 경우는 없다. -> 발전소 연결된 노드부터 시작하기 때문에
         *
         *
         * */
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            Set<Integer> fac = new HashSet<>();
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < k; i++) {
                fac.add(Integer.parseInt(st.nextToken()));
            }

            Map<Integer, List<int[]>> graph = new HashMap<>();
            // 노드 양방향 연결
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());

                List<int[]> values = graph.computeIfAbsent(u, key -> new ArrayList<>());
                values.add(new int[]{v, w});

                List<int[]> values2 = graph.computeIfAbsent(v, key -> new ArrayList<>());
                values2.add(new int[]{u, w});
            }

            // u , v , w
            PriorityQueue<int[]> pq = new PriorityQueue<>((p1, p2) -> p1[2] - p2[2]);
            // 초기 값 설정 : 발전소와 연결된 노드들
            for (int f : fac) {
                List<int[]> values = graph.get(f);
                for (int[] value : values) {
                    pq.add(new int[]{f, value[0], value[1]});
                }
            }

            int[] parent = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }

            int answer = 0;
            while (!pq.isEmpty()) {
                if (isConnect(parent, fac)) break;
                int[] curr = pq.poll();

                int up = getParent(curr[0], parent);
                int vp = getParent(curr[1], parent);

                // 이미 두 노드 모두 발전소와 연결된 상태면 skip
                if (fac.contains(up) && fac.contains(vp)) continue;

                // union
                if (fac.contains(up)) {
                    parent[vp] = up;
                    for (int[] value : graph.get(curr[1])) {
                        pq.add(new int[]{curr[1], value[0], value[1]});
                    }
                } else {
                    parent[up] = vp;
                    for (int[] value : graph.get(curr[0])) {
                        pq.add(new int[]{curr[0], value[0], value[1]});
                    }
                }

                answer += curr[2];
            }

            System.out.println(answer);
        }

        private static boolean isConnect(int[] parent, Set<Integer> fac) {
            for (int p : parent) {
                if (!fac.contains(getParent(p, parent))) return false;
            }
            return true;
        }

        private static int getParent(int curr, int[] parent) {
            if (curr == parent[curr]) return curr;
            return parent[curr] = getParent(parent[curr], parent);
        }
    }

}
