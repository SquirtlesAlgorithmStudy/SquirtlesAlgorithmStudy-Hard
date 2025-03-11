// 백준 15685 드래곤커브
#include <iostream>
#include <vector>

using namespace std;

int board[101][101];

// 동 북 서 남
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void drawDragonCurve(int x, int y, int d, int g)
{
    vector<int> directions;  // 방향 동0북1서2남3
    directions.push_back(d); // 0세대 방향 추가
    // g세대 까지 방향 생성
    for (int i = 0; i < g; ++i)
    {
        int size = directions.size(); // 추가된 선들의 방향을 저장하는 list생성
        for (int j = size - 1; j >= 0; --j)
        {                                                  // 뒤에 붙이기 때문에 list의 마지막(size-1)부터 읽어야
            directions.push_back((directions[j] + 1) % 4); // 90도 회전 후 추가
        }
    }

    board[y][x] = 1; // 세로: [y], 가로: [x]
    for (int dir : directions)
    {
        x += dx[dir];
        y += dy[dir];
        board[y][x] = 1; // 선분의 끝점 표시
    }
}

int countsquare()
{
    int count = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
            { // 네 꼭짓점이 모두 포함되면 count
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int N; // dragon curve#
    cin >> N;

    // dragon curve input
    for (int i = 0; i < N; ++i)
    {
        int x, y, d, g; // 시작점(x,y), 시작방향(d), 세대(g) / 방향 동0북1서2남3
        cin >> x >> y >> d >> g;
        drawDragonCurve(x, y, d, g);
    }

    cout << countsquare() << endl;

    return 0;
}