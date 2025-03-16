// 백준 14502 연구소(복습)

// 목표는 벽을 3개를 세운 뒤 안정 영역의 크기를 최대값(max_safe_area)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M; // 연구소
int lab[8][8];
int temp_lab[8][8];

vector<pair<int, int>> empty_space; // 방전체 보다는 격자에 적혀진 내용이 관심이 있기 때문에 <int,int>
vector<pair<int, int>> virus;

// 동서남북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 바이러스 퍼뜨리는 법
void spread_virus_bfs()
{
    queue<pair<int, int>> q; // <x,y>
    for (auto v : virus)
    {              // v = virus = <x,y>
        q.push(v); // [<x,y>   ]
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 상하좌우로 바이러스 퍼뜨리기 위해 반복
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && temp_lab[nx][ny] == 0)
            {
                temp_lab[nx][ny] = 2; // virus=2
                q.push({nx, ny});
            }
        }
    }
}

// 안전한 공간(0) 찾는법
int calculate_safe_area()
{
    int safe_area = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp_lab[i][j] == 0)
            {
                safe_area++;
            }
        }
    }
    return safe_area;
}

// 실제로 돌려
int searching_safe_area()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            temp_lab[i][j] = lab[i][j];
        }
    }
    spread_virus_bfs();

    return calculate_safe_area();
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 0)
            {
                empty_space.push_back({i, j});
            }

            if (lab[i][j] == 2)
            {
                virus.push_back({i, j});
            }
        }
    }

    int max_safe_area = 0;
    // for문 돌려서 벽1 3개 설치
    for (int i = 0; i < empty_space.size(); i++)
    {
        for (int j = i + 1; j < empty_space.size(); j++)
        {
            for (int k = j + 1; k < empty_space.size(); k++)
            {
                lab[empty_space[i].first][empty_space[i].second] = 1; // 벽을 세우고
                lab[empty_space[j].first][empty_space[j].second] = 1;
                lab[empty_space[k].first][empty_space[k].second] = 1;

                int safe_area = searching_safe_area(); // 실제로 돌려

                max_safe_area = max(safe_area, max_safe_area); // 업데이트

                lab[empty_space[i].first][empty_space[i].second] = 0;
                lab[empty_space[j].first][empty_space[j].second] = 0;
                lab[empty_space[k].first][empty_space[k].second] = 0;
            }
        }
    }

    cout << max_safe_area << endl;

    return 0;
}