// 16234 인구이동2

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R;
int A[50][50]; // 인구 수 배열
bool visited[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;               // 현재 탐색하고 있는 나라의 좌표 저장
    vector<pair<int, int>> unionCountries; // 연합을 이루는 나라 vector에 동적으로 저장
    q.push({x, y});                        // 현재 나라 일단 넣어
    unionCountries.push_back({x, y});
    visited[x][y] = true;

    int total_population = A[x][y];
    int count = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny])
            {
                int diff = abs(A[cx][cy] - A[nx][ny]);
                if (L <= diff && diff <= R)
                {
                    q.push({nx, ny});
                    unionCountries.push_back({nx, ny});
                    visited[nx][ny] = true;
                    total_population += A[nx][ny];
                    count++;
                }
            }
        }
    }

    // 인구이동처리
    if (count > 1)
    {
        int new_population = total_population / count;
        for (auto &country : unionCountries)
        {
            A[country.first][country.second] = new_population;
        }
        return true;
    }
    return false;
}

int main()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    }

    int days = 0;

    while (true)
    {
        bool moved = false;                          // 인구이동이 일어났는지 확인
        fill(&visited[0][0], &visited[N][0], false); // 방문 여부 초기화

        // 모든 나라에 대해 연합을 찾고
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (!visited[i][j])
                { // 아직 방문하지 않았다면
                    if (bfs(i, j))
                    { // 연합을 찾고
                        moved = true;
                    }
                }
            }
        }

        if (!moved)
            break;
        days++;
    }

    cout << days << endl;
    return 0;
}