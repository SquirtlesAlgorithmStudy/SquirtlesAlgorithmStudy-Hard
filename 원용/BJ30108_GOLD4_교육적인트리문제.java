package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
* graph
*   p : 1 , child [ 2, 3 ]
*   p : 2 , child [ 4 ]
*
* 1. pq에 [idx, weight] 배열을 넣는다.
* 2. pop 을 하고, 현재 weight를 누적한다.
* 3. 현재 pop한 idx의 자식 노드들을 pq에 넣는다.
* 4. 2~3번을 반복한다.
*
* */
public class BJ30108_GOLD4_교육적인트리문제 {

    class Main {
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());

            Map<Long, List<Long>> graph = new HashMap<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (long i = 2; i <= n; i++) {
                long p = Long.parseLong(st.nextToken());
                if (graph.containsKey(p)) {
                    graph.get(p).add(i);
                } else {
                    List<Long> child = new ArrayList<>();
                    child.add(i);
                    graph.put(p, child);
                }
            }

            st = new StringTokenizer(br.readLine());
            long[] nums = new long[n];
            for (int i = 0; i < n; i++) {
                nums[i] = Long.parseLong(st.nextToken());
            }

            // 0: idx , 1: weight
            // weight 별 내림차순
            PriorityQueue<long[]> pq = new PriorityQueue<>((p1, p2) -> (int) (p2[1] - p1[1]));
            pq.add(new long[]{1, nums[0]});

            StringBuilder sb = new StringBuilder();
            long acc = 0;
            for (int i = 0; i < n; i++) {
                long[] curr = pq.poll();
                long idx = curr[0];
                long w = curr[1];
                acc += w;
                sb.append(acc).append("\n");

                List<Long> child = graph.get(idx);
                if (child == null) continue;
                for (long c : child) {
                    pq.add(new long[]{c, nums[(int) (c - 1)]});
                }
            }

            System.out.println(sb);
        }
    }
}
