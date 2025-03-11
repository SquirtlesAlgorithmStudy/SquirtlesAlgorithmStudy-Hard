// 백준 2190 뱀(복습)

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

int N; // 보드 크기
int K; // 사과 갯수
int L; // 회전 횟수

int board[101][101];
vector<pair<int, char>> moves; // <X초 후 /(L왼쪽 D오른쪽)>

// 우 하 좌 상
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 1. 회전방법
int turn(int dir, char c)
{
    if (c == 'L')
    {
        return (dir + 3) % 4;
    }
    else
    {
        return (dir + 1) % 4;
    }
}

// 2. 몇 초 후에 끝나는지
int simulate()
{
    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    board[1][1] = 2; // 뱀 2 사과 1 빈칸 0

    int time = 0;
    int moveIdx = 0;
    int x = 1;
    int y = 1;
    int dir = 0; // 0우 1하 2좌 3상

    while (true)
    {
        time++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx > N || ny > N || nx < 1 || ny < 1 || board[nx][ny] == 2)
        {
            return time;
        }
        if (board[nx][ny] == 1)
        {
            snake.push_front({nx, ny});
            board[nx][ny] = 2;
        }
        else
        {
            board[nx][ny] = 2;
            snake.push_front({nx, ny});
            int tx = snake.back().first;
            int ty = snake.back().second;
            snake.pop_back();
            board[tx][ty] = 0;
        }

        if (moveIdx < L && time == moves[moveIdx].first)
        {
            dir = turn(dir, moves[moveIdx].second);
            moveIdx++;
        }
        x = nx;
        y = ny;
    }
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        // K 개의 사과 위치
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 사과 =1, 뱀 =2;
    }
    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        int X; // X초 후 (C : L왼쪽 D오른쪽)
        char C;
        cin >> X >> C;
        moves.push_back({X, C});
    }
    cout << simulate() << endl;

    return 0;
}