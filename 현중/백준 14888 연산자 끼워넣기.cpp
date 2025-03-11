// 백준 14888 연산자 끼워넣기 (DFS)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> A;
int oper[4]; // 0+,1-,2*,3/
int maxResult = -1e9, minResult = 1e9;

void dfs(int idx, int currentResult)
{
    if (idx == N)
    {
        maxResult = max(maxResult, currentResult);
        minResult = min(minResult, currentResult);
        return;
    }

    if (oper[0] > 0)
    {
        oper[0]--;
        dfs(idx + 1, currentResult + A[idx]);
        oper[0]++;
    }

    if (oper[1] > 0)
    {
        oper[1]--;
        dfs(idx + 1, currentResult - A[idx]);
        oper[1]++;
    }

    if (oper[2] > 0)
    {
        oper[2]--;
        dfs(idx + 1, currentResult * A[idx]);
        oper[2]++;
    }

    if (oper[3] > 0)
    {
        oper[3]--;
        dfs(idx + 1, currentResult / A[idx]);
        oper[3]++;
    }
}

int main()
{
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        cin >> oper[i];
    }

    dfs(1, A[0]); // idx, currentResult

    cout << maxResult << endl;
    cout << minResult << endl;

    return 0;
}
