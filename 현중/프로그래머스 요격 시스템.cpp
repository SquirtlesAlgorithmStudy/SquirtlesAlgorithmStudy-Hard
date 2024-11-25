// 프로그래머스 요격 시스템

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets)
{
    sort(targets.begin(), targets.end(), [](const vector<int> &a, const vector<int> b)
         { return a[1] < b[1]; });

    int ssard = 0;
    int nowend = -1;

    for (const auto &target : targets)
    {
        int start = target[0];
        int end = target[1];

        if (nowend <= start)
        {
            ssard++;
            nowend = end;
        }
    }

    return ssard;
}

int main()
{
    int n;
    cin >> n; // target의 갯수
    vector<vector<int>> targets(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        cin >> targets[i][0] >> targets[i][1];
    }

    cout << solution(targets) << endl;

    return 0;
}