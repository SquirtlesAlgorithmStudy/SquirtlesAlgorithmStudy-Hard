// 1206. 조망권확보
// x< 1000
// h< 255
// input = 10

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    for (int test_case = 1; test_case <= 10; test_case++)
    {
        int N;
        cin >> N;
        vector<int> buildings(N);

        for (int i = 0; i < N; i++)
        {
            cin >> buildings[i];
        }

        int total_view = 0;

        for (int i = 2; i < N - 2; i++)
        {
            int left_max = max(buildings[i - 1], buildings[i - 2]);
            int right_max = max(buildings[i + 1], buildings[i + 2]);

            int max_height = max(left_max, right_max);

            if (buildings[i] > max_height)
            {

                total_view += (buildings[i] - max_height);
            }
        }
        cout << "#" << test_case << "" << total_view << endl;
    }

    return 0;
}
