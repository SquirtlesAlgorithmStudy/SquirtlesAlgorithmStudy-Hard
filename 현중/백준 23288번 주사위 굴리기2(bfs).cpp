// 백준 23288번 주사위 굴리기2 (bfs)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K;
int board[20][20];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dice[6] = {1, 2, 3, 5, 4, 6}; // 주사위의 면을 저장 (0:위, 1:앞, 2:오른쪽, 3:뒤, 4:왼쪽, 5:아래)

// 1. 주사위돌리기
void rollDice(int dir)
{
    int temp[6];
    for (int i = 0; i < 6; ++i)
        temp[i] = dice[i];

    if (dir == 0)
    { // 동쪽으로 이동
        dice[0] = temp[4];
        dice[2] = temp[0];
        dice[5] = temp[2];
        dice[4] = temp[5];
    }
    else if (dir == 1)
    { // 남쪽으로 이동
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[5] = temp[3];
        dice[3] = temp[0];
    }
    else if (dir == 2)
    { // 서쪽으로 이동
        dice[0] = temp[2];
        dice[2] = temp[5];
        dice[5] = temp[4];
        dice[4] = temp[0];
    }
    else
    { // 북쪽으로 이동
        dice[0] = temp[3];
        dice[1] = temp[0];
        dice[5] = temp[1];
        dice[3] = temp[5];
    }
}

int CalculateScore(int x, int y)
{
    int Score = board[x][y]; // B
    int count = 0;           // C
    bool visited[20][20] = {false};
    queue<pair<int, int>> q;

    // 주사위가 있는 곳에서 bfs시작
    q.push({x, y});
    visited[x][y] = true;
    count++;

    // bfs시작
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && board[nx][ny] == Score)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                count++;
            }
        }
    }
    return count * Score;
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    int x = 0;
    int y = 0;
    int dir = 0;
    int totalScore = 0;

    // K번이동
    for (int i = 0; i < K; ++i)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        {
            // 지도를 벗어난다면 반대쪽으로
            dir = (dir + 2) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        // 주사위 굴림
        rollDice(dir);
        x = nx;
        y = ny;

        // 점수 획득
        totalScore += CalculateScore(x, y);

        // 아랫면 & Score로 방향결정
        int A = dice[5];
        int B = board[x][y];

        if (A > B)
        {
            dir = (dir + 1) % 4;
        }
        else if (A < B)
        {
            dir = (dir + 3) % 4;
        }
    }

    cout << totalScore << endl;

    return 0;
}