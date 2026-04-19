package 원용;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ5052_GOLD4_전화번호목록 {
    /*
     * 1. 문자열 기준으로 값을 정렬
     * 2. 현재 값의 prefix가 직전 값을 포함하면 false
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            String[] arr = new String[n];

            for (int j = 0; j < n; j++) {
                arr[j] = br.readLine();
            }

            Arrays.sort(arr);

            boolean isAns = true;
            String last = arr[0];
            for (int j = 1; j < n; j++) {
                if (arr[j].startsWith(last)) {
                    isAns = false;
                    break;
                }
                last = arr[j];
            }

            if (isAns) sb.append("YES");
            else sb.append("NO");
            sb.append("\n");
        }

        System.out.println(sb);
    }
}
