package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ22252_GOLD3_공정컨설턴트호석 {

    class Main {

        /*
         * 파라메트릭 서치
         * 기준 : 공정 라인 개수 -> logN
         *
         * k가 작을 수록 정답
         * if 실행 시간 > x : (공정 라인 증가해야 함) -> min = mid+1
         * else : max = mid - 1
         *
         * 공정 라인 개수가 k 일 때 실행 시간 계산 하기
         * (n) min pq에 mid 개수 만큼 0을 넣는다.
         * (n) 선물 순회한다.
         *      min값 poll <- log(n)
         *      add(현재 값 + poll한 값) <- log(n)
         * n log(n)
         *
         * 실행시간 : log(n) * n log(n)
         *
         * */
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            int[] nums = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }

            int min = 1;
            int max = 100_001;

            while (min <= max) {
                int mid = (min + max) / 2;

                /*
                 * 공정 라인이 k일 때 실행 시간은 pq 마지막에 있는 값인데
                 * 이를 구하기 위해서 또 한번 pq를 순회하기 보다 pq를 계산하면서 최대 값을 저장한다.
                 * */
                int temp = -1;
                PriorityQueue<Integer> pq = new PriorityQueue<>();
                for (int num : nums) {
                    int time;
                    if (pq.size() < mid) {
                        time = num;
                    } else {
                        time = pq.poll() + num;
                    }
                    temp = Math.max(temp, time);
                    pq.add(time);
                }

                if (temp > x) min = mid + 1;
                else max = mid - 1;
            }

            System.out.println(min);
        }
    }
}
