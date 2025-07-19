public class BJ1700_GOLD1멀티탭스케줄링 {
    /**
     * 반례
     *  2 4
     *  1 1 1 3
     *  이렇게 했을 때 0이 되어야 함
     *
     * 플래그가 가득 차있을 때, 현재 플래그에 있는 기구들 중에 가장 뒤에 나오는 기구를 제거한다.
     *
     * 입력 값을 받을 때, 기구가 나오는 순서를 기록한다.
     * 기구들을 순회한다.
     *  1. 비어 있는 곳이 있으면 빈 곳에 넣는다.
     *  2. 비어 있는 곳이 없다면
     *      2-1. 현재 기구가 플래그에 있는지 확인하고, 있다면 스킵한다.
     *      2-2. 없다면 현재 플래그에 있는 기구들 중에 뽑을 기구를 선택한다.
     *          기준1. 뒤에 아예 안나오는 경우  , index.isEmpty() 임
     *          기준2. 가장 나중에 나오는 경우 , index.peek() 값이 가장 큼
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        if (n >= k) {
            System.out.println(0);
            return;
        }

        int[] products = new int[k];
        st = new StringTokenizer(br.readLine());
        Map<Integer, Queue<Integer>> index = new HashMap<>();
        for (int i = 0; i < k; i++) {
            products[i] = Integer.parseInt(st.nextToken());
            if (index.containsKey(products[i])) {
                index.get(products[i]).add(i);
            } else {
                Queue<Integer> que = new LinkedList<>();
                que.add(i);
                index.put(products[i], que);
            }
        }

        int[] flags = new int[n];
        int answer = 0;
        for (int i = 0; i < k; i++) {
            int p = products[i];

            boolean isZero = false;
            boolean isContains = false;
            for (int j = 0; j < n; j++) {
                if (flags[j] == 0) {
                    isZero = true;
                    break;
                }
                if (flags[j] != p) continue;
                isContains = true;
                break;
            }

            if (isZero) {
                for (int j = 0; j < n; j++) {
                    if (flags[j] != 0) continue;
                    flags[j] = p;
                    break;
                }
            } else {
                if (!isContains) {
                    int max = Integer.MIN_VALUE;
                    int idx = -1;
                    for (int j = 0; j < n; j++) {
                        int f = flags[j];
                        if (index.get(f).isEmpty()) {
                            idx = j;
                            break;
                        }
                        int curr = index.get(f).peek();
                        if (max >= curr) continue;
                        max = curr;
                        idx = j;
                    }

                    flags[idx] = p;
                    answer++;
                }
            }

            index.get(p).poll();
        }

        System.out.println(answer);
    }
}
