// 백준 15683 감시

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> office;
vector<pair<int, int>> cctvs; // cctvs <위치, 5중 종류>

int canspin[5] = {4, 2, 4, 4, 1}; // cctv 종류별로 회전할 수 있는 경우의 수
int minBlindspot = 1e9;

int dx[] = {-1, 0, 1, 0}; // 상 우 하 좌
int dy[] = {0, 1, 0, -1};

// 특정 방향으로 cctv가 감시할 수 있는 영역을 표시해서 죽임 (출력 = 사각지대)
void watch(int x, int y, int dir, vector<vector<int>> &tempoffice)
{ // 방향마다 tempoffice를 복사해서 수행
    dir %= 4;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];

        // 경계를 만나거나 벽을 만나면 감시 중단
        if (x < 0 || y < 0 || x >= N || y >= M || tempoffice[x][y] == 6)
            break;

        // 감시 가능한 곳 죽여
        if (tempoffice[x][y] == 0)
        {
            tempoffice[x][y] = -1;
        }
    }
}

// cctv의 모든 방향을 설정하여 사각지대 찾아
void dfs(int idx, vector<vector<int>> tempoffice)
{ // 현재 처리중인 cctv# <0,1,2,3,4> / office 복사
    if (idx == cctvs.size())
    { // 만약 idx끝까지 cctv 처리를 끝냈다면
        int blindspot = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (tempoffice[i][j] == 0)
                { //
                    blindspot++;
                }
            }
        }
        minBlindspot = min(minBlindspot, blindspot);
        return;
    }

    int x = cctvs[idx].first;
    int y = cctvs[idx].second;
    int cctvType = office[x][y] - 1;
    for (int d = 0; d < canspin[cctvType]; ++d)
    {
        vector<vector<int>> newOffice = tempoffice; // 새로운 사무실 복사
        // cctv종류에 따라 다른 방향 감시
        if (cctvType == 0)
        {
            watch(x, y, d, newOffice);
        }
        else if (cctvType == 1)
        {
            watch(x, y, d, newOffice);
            watch(x, y, d + 2, newOffice);
        }
        else if (cctvType == 2)
        {
            watch(x, y, d, newOffice);
            watch(x, y, d + 1, newOffice);
        }
        else if (cctvType == 3)
        {
            watch(x, y, d, newOffice);
            watch(x, y, d + 1, newOffice);
            watch(x, y, d + 2, newOffice);
        }
        else if (cctvType == 4)
        {
            watch(x, y, d, newOffice);
            watch(x, y, d + 1, newOffice);
            watch(x, y, d + 2, newOffice);
            watch(x, y, d + 3, newOffice);
        }
        dfs(idx + 1, newOffice);
    }
}

int main()
{
    cin >> N >> M;
    office.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5)
            {
                cctvs.push_back({i, j});
            }
        }
    }
    dfs(0, office);
    cout << minBlindspot << endl;

    return 0;
}