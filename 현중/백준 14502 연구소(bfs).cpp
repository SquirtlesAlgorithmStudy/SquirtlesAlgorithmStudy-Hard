// 백준 14502 연구소

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int lab[8][8];      // 연구소 지도 작성
int temp_lab[8][8]; // 3개의 벽을 세운 후 연구소

vector<pair<int, int>> empty_space; // 빈공간 벡터 : 빈공간을 찾아서 벽을 세울 때, 매번 0,1,2를 모두 뒤지는게 아닌 0만 empty_spaces라는 벡터에 저장해두고 3개를 조합
vector<pair<int, int>> viruses;     // 바이러스 벡터

// 남 북 서 동
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 2. bfs로 바이러스 퍼뜨리기
void spread_virus()
{
    queue<pair<int, int>> q;
    for (auto v : viruses)
    {              // 1.1 바이러스가 있는 위치를 모두 queue에 넣음
        q.push(v); // 1.2 viruses가 원래 pair<int,int> -> v : pair<int,int> (바이러스가 있는 위치를 하나씩 큐에 삽입)
    }

    while (!q.empty()) // 큐가 비어있지 않은 동안(= 퍼뜨릴 바이러스가 남아있는 동안)
    {
        int x = q.front().first;  // 큐의 앞에 있는 바이러스의 x 좌표
        int y = q.front().second; // 큐의 앞에 있는 바이러스의 y 좌표
        q.pop();                  // 큐에서 해당 바이러스를 제거

        for (int i = 0; i < 4; ++i) // 상하좌우 네 방향으로 바이러스를 퍼뜨리기 위해 반복
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 1.3 범위내 && 빈칸(0)일때만
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && temp_lab[nx][ny] == 0)
            {
                temp_lab[nx][ny] = 2; // 1.4 바이러스 퍼뜨려 (3개의 벽은 이미 세움)
                q.push({nx, ny});     // 새로운 좌표를 큐에 추가하여 다음에 바이러스를 퍼뜨릴 수 있도록 함
            }
        }
    }
}

// 3. 안전영역 계산
int calculate_safe_area()
{
    int safe_area = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (temp_lab[i][j] == 0)
            {
                safe_area++;
            }
        }
    }
    return safe_area;
}

// 1. 시뮬레이션을 위한 함수
int simulate()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            temp_lab[i][j] = lab[i][j];
        }
    }

    spread_virus(); // 2.

    return calculate_safe_area(); // 3.
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 0)
            {
                empty_space.push_back({i, j}); // (empty_space: 빈칸0만 모아두고 그중에서 3개 선택하기 위해)
            }
            if (lab[i][j] == 2)
            {
                viruses.push_back({i, j});
            }
        }
    }

    int max_safe_area = 0;
    // 3개의 벽 설치
    // 0.중 3개를 골라 1을 설치하는 따라서 3번의 for필요
    for (int i = 0; i < empty_space.size(); ++i)
    {
        for (int j = i + 1; j < empty_space.size(); ++j)
        {
            for (int k = j + 1; k < empty_space.size(); ++k)
            {
                lab[empty_space[i].first][empty_space[i].second] = 1;
                lab[empty_space[j].first][empty_space[j].second] = 1;
                lab[empty_space[k].first][empty_space[k].second] = 1;

                int safe_area = simulate();

                max_safe_area = max(safe_area, max_safe_area); // max_safe_area와 safe_area 중 큰 걸 반환

                lab[empty_space[i].first][empty_space[i].second] = 0;
                lab[empty_space[j].first][empty_space[j].second] = 0;
                lab[empty_space[k].first][empty_space[k].second] = 0;
            }
        }
    }

    cout << max_safe_area << endl;

    return 0;
}