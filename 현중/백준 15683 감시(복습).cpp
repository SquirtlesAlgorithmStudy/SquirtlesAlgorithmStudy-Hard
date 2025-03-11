// 백준 15683 감시(복습)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // board size
vector<vector<int>> board;
vector<pair<int, int>> cctvs;

int canspin[5] = {4, 2, 4, 4, 1}; // 각 CCTV 유형별로 회전할 수 있는 경우의 수
int minBlindspot = 1e9;

int dx[] = {-1, 0, 1, 0}; // 동서남북
int dy[] = {0, 1, 0, -1};

// 봐
void watch(int cx, int cy, int dir, vector<vector<int>> &tempboard)
{
    dir %= 4;
    while (true)
    {
        cx = cx + dx[dir];
        cy = cy + dy[dir];

        // 중단조건
        if (cx < 0 || cy < 0 || cx >= N || cy >= M || tempboard[cx][cy] == 6)
        {
            break;
        }

        if (tempboard[cx][cy] == 0)
        {
            tempboard[cx][cy] = -1; // 우리의 목표는 사각지대 갯수가 최소!
        }
    }
}

// 사각지대 찾아
void dfs(int idx, vector<vector<int>> tempboard)
{
    if (idx == cctvs.size())
    {
        int blindspot = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (tempboard[i][j] == 0)
                {
                    blindspot++;
                }
            }
        }
        minBlindspot = min(minBlindspot, blindspot);
        return;
    }

    int x = cctvs[idx].first;
    int y = cctvs[idx].second;
    int cctvstype = board[x][y] - 1; // board[x][y] = 1~5 , canspin[5] = {4,2,4,4,1} = 0~4
    for (int dir = 0; dir < canspin[cctvstype]; dir++)
    {
        vector<vector<int>> newboard = tempboard;
        if (cctvstype == 0)
        {
            watch(x, y, dir, newboard);
        }
        else if (cctvstype == 1)
        {
            watch(x, y, dir, newboard);
            watch(x, y, dir + 2, newboard);
        }
        else if (cctvstype == 2)
        {
            watch(x, y, dir, newboard);
            watch(x, y, dir + 1, newboard);
        }
        else if (cctvstype == 3)
        {
            watch(x, y, dir, newboard);
            watch(x, y, dir + 1, newboard);
            watch(x, y, dir + 2, newboard);
        }
        else if (cctvstype == 4)
        {
            watch(x, y, dir, newboard);
            watch(x, y, dir + 1, newboard);
            watch(x, y, dir + 2, newboard);
            watch(x, y, dir + 3, newboard);
        }
        dfs(idx + 1, newboard);
    }
}

// 우리의 목표는 사각지대 갯수가 최소!
int main()
{
    cin >> N >> M;
    board.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5)
            {
                cctvs.push_back({i, j});
            }
        }
    }
    dfs(0, board);
    cout << minBlindspot << endl;

    return 0;
}