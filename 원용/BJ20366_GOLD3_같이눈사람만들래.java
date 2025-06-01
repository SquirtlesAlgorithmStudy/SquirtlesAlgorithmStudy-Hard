package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BJ20366_GOLD3_같이눈사람만들래 {
    /*
     * 서로 다른 눈덩이 4개 선택
     *   아래 눈덩이는 위 눈덩이 보다 크거나 같아야 함
     *   두 눈사람의 차가 제일 작은 것
     * N = 600
     *
     * 600C4 = 600 * 10^4 = 6*10^8 약 6초?
     *
     * 나올 수 있는 2개의 눈덩이 합을 모두 구한 뒤
     * 바로 옆에 있는 눈덩이의 차를 구한다.
     *      가능한 조합인지 확인한다.
     *
     * 결과: 4000초, 엄청 느림 : https://www.acmicpc.net/source/94962205
     *
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] nums = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        // key: 2개의 합, value: 나올 수 있는 조합 [원소 1 인덱스, 원소2 인덱스]
        List<int[]> sums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int[] temp = new int[3];
                temp[0] = nums[i] + nums[j];
                temp[1] = i;
                temp[2] = j;

                sums.add(temp);
            }
        }

        Collections.sort(sums, (a1, a2) -> a1[0] - a2[0]);

        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < sums.size(); i++) {
            for (int j = i + 1; j < sums.size(); j++) {
                int[] first = sums.get(i);
                int[] second = sums.get(j);

                Set<Integer> validate = new HashSet<>();
                validate.add(first[1]);
                validate.add(first[2]);
                validate.add(second[1]);
                validate.add(second[2]);

                if (validate.size() != 4) continue;

                answer = Math.min(answer, Math.abs(second[0] - first[0]));
                break;
            }
        }

        System.out.println(answer);
    }
}
