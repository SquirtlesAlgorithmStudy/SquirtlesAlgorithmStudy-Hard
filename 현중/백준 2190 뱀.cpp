// 백준 2190 뱀

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

int N, K, L; // board크기 N, 사과갯수K, 회전횟수L
int board[101][101];
vector<pair<int, char>> moves; // move정보에 int초 후에 char방향으로 회전('L', 'D')

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 1. 방향 방법
int turn(int dir, char c)
{
    if (c == 'L')
    {
        return (dir + 3) % 4; // 좌회전
    }
    else
    {
        return (dir + 1) % 4; // 우회전
    }
}

// 2.
int simulate()
{
    deque<pair<int, int>> snake; // deque를 이용하여 뱀의 몸 위치 저장
    snake.push_back({1, 1});     // 뱀 시작위치 1,1
    board[1][1] = 2;             // 뱀=2 / 빈=0 / 사과=1

    int time = 0;
    int x = 1, y = 1;
    int dir = 0;     // 처음에는 동쪽0을 보고 시작
    int moveIdx = 0; // 방향 전환 정보 Idx

    while (true)
    {
        time++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 1 || ny < 1 || nx > N || ny > N || board[nx][ny] == 2)
        { // 범위 밖이나 자기자신과 부딫히면
            return time;
        }

        if (board[nx][ny] == 1)
        { // 만약 사과가 있어?
            board[nx][ny] = 2;
            snake.push_front({nx, ny}); // [(1,1)] -> [(1,2),(1,1)]
        }
        else
        { // 만약 사과가 없어?
            board[nx][ny] = 2;
            snake.push_front({nx, ny});  // [(1,1)] -> [(1,2),(1,1)]
            int tx = snake.back().first; // deque<pair<int,int>> snake
            int ty = snake.back().second;
            snake.pop_back();
            board[tx][ty] = 0;
        }

        // 현재 시간이 방향을 바꿀 시간인 경우
        if (moveIdx < L && time == moves[moveIdx].first)
        {                                           // move정보에 int초 후!!!!! 에 char방향으로 회전('L', 'D')
            dir = turn(dir, moves[moveIdx].second); // move정보에 int초 후에 char방향으로 회전('L', 'D')!!!!!!!
            moveIdx++;
        }

        x = nx;
        y = ny;
    }
}

// 사과 : 1, 뱀 : 2
int main()
{
    cin >> N;
    cin >> K;

    // 사과위치 입력
    for (int i = 0; i < K; ++i)
    {
        int x, y; // 사과위치 입력받기위해
        cin >> x >> y;
        board[x][y] = 1;
    }

    // 뱀방향
    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        int X;  // X초 후
        char C; // C방향으로 L 또는 D
        cin >> X >> C;
        moves.push_back({X, C});
    }
    cout << simulate() << endl;

    return 0;
}