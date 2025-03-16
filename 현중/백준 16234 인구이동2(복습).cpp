// 백준 16234 인구이동2

#include <iostream>
#include <vector>
#include <cmath>
#include <queue> // 최단거리, 빠른 경로 이런 단어가 나올 때

using namespace std;

int N, L, R; // N개의 행렬, L < 인구차이 <R
int A[50][50];
bool visited[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y)
{
    queue<pair<int, int>> q;               // 현재 탐색하고 있는 나라의 좌표 저장
    vector<pair<int, int>> unionCountries; // 연합을 이루는 나라를 저장하기 위한 vector에 동적으로 저장
    q.push({x, y});                        // 현재 나라 (0,0)을 queue에 일단 추가
    unionCountries.push_back({x, y});      // 연합에0 (0,0)을 추가
    visited[x][y] = true;

    int total_population = A[x][y];
    int Count = 1;

    while (!q.empty())
    {
        int cx = q.front().first; // current queue에 저장된 가장 앞의 pair<int,int>를 가져와
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위 내에 있는 국가들을 탐색
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny])
            {
                int diff = abs(A[cx][cy] - A[nx][ny]);
                if (L <= diff && diff <= R)
                {
                    q.push({nx, ny});
                    unionCountries.push_back({nx, ny});
                    visited[nx][ny] = true;
                    total_population += A[nx][ny];
                    Count++;
                }
            }
        }
    }

    // 이동인구 처리
    if (Count > 1)
    {
        int new_population = total_population / Count;
        for (auto &country : unionCountries)
        {
            A[country.first][country.second] = new_population;
        }

        return true;
    }

    return false;
}

// 우리의 목표는 인구이동이 며칠(Count) 동안 발생하는지 출력
int main()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    int days = 0;

    while (true)
    {
        // 움직임 초기화, 방문 초기화
        bool move = false;
        fill(&visited[0][0], &visited[N][0], false);

        // 모든 나라에 대해 연합을 찾고
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                { // 아직 방문하지 않았다면
                    if (bfs(i, j))
                    { // 연합을 찾고
                        move = true;
                    }
                }
            }
        }

        if (!move)
            break;
        days++;
    }

    cout << days << endl;

    return 0;
}
