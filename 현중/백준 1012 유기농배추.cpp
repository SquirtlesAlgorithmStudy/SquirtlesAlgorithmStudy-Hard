// 백준 1012 유기농배추

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int testcase;
int M, N, K;

int board[51][51];
int visited[51][51];

int dx[] = {0, 0, 1, -1}; // 상, 하, 좌, 우
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && board[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> testcase;
    while (testcase--)
    {
        cin >> M >> N >> K;

        // board 초기화
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                board[i][j] = 0;
                visited[i][j] = false;
            }
        }

        // 배추위치입력
        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int worm = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 1 && !visited[i][j])
                {
                    bfs(i, j);
                    worm++;
                }
            }
        }
        cout << worm << endl;
    }

    return 0;
}