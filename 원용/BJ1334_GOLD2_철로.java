package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ1334_GOLD2_철로 {

    /*
     * - 이진 탐색을 생각했지만, 오른쪽 왼쪽을 어떻게 구분할지 모르겠어서 포기
     *
     * - 우선순위큐 사용 (끝점 기준 PQ, 앞점 기준 PQ)
     *  - 입력 값들을 끝점 기준 PQ에 넣는다.
     *  - pq를 하나씩 poll
     *      - 현재 위치의 (끝점-거리)를 한다.
     *      - 앞점 기준 PQ의 peek 값이 현재 (끝점-거리) 값보다 작은 것들은 모두 poll 한다. (포함안되는 것들 제거)
     *      - 앞점 >= 거리 일 때만 앞점 기준 PQ에 넣는다.
     *      - 최대 값을 갱신한다.
     *
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        PriorityQueue<int[]> divs = new PriorityQueue<>((d1, d2) -> {
            if (d1[1] == d2[1]) return d1[0] - d2[0];
            return d1[1] - d2[1];
        });

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            int o = Integer.parseInt(st.nextToken());

            if (h > o) {
                divs.add(new int[]{o, h});
            } else {
                divs.add(new int[]{h, o});
            }
        }
        int d = Integer.parseInt(br.readLine());

        int answer = Integer.MIN_VALUE;
        PriorityQueue<int[]> pos = new PriorityQueue<>((d1, d2) -> {
            return d1[0] - d2[0];
        });
        while (!divs.isEmpty()) {
            int[] div = divs.poll();
            int end = div[1];
            int start = end - d;

            while (!pos.isEmpty() && start > pos.peek()[0]) {
                pos.poll();
            }

            if (div[0] >= start) {
                pos.add(div);
            }

            answer = Math.max(answer, pos.size());
        }

        System.out.println(answer);
    }

}
