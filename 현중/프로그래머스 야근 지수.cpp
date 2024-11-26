// 프로그래머스 야근 지수
// prioritry_queue

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works)
{
    priority_queue<int> pq(works.begin(), works.end());

    while (n > 0 && !pq.empty())
    {
        int maxWork = pq.top();
        pq.pop();

        if (maxWork > 0)
        {
            maxWork--;
            n--;
            pq.push(maxWork);
        }
    }

    // 각 work 제곱한 후 합
    long long overtimeIndex = 0;
    while (!pq.empty())
    {
        int work = pq.top();
        pq.pop();
        overtimeIndex += (long long)work * work;
    }

    return overtimeIndex;
}

int main()
{
    int n; // 시간
    cin >> n;

    int m; // 작업량
    cin >> m;
    vector<int> works(m);
    for (int i = 0; i < m; i++)
    {
        cin >> works[i];
    }

    cout << solution(n, works) << endl;

    return 0;
}