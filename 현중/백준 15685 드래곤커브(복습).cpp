// 백준 15685 드래곤커브(복습)

#include <iostream>
#include <vector>

using namespace std;

int N;

int board[101][101];

// 동0북1서2남3
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void drawdragoncurve(int x, int y, int d, int g)
{

    vector<int> direction;  // 방향 동0북1서2남3
    direction.push_back(d); // 0세대 방향 추가

    // 1. 1세대 부터 g세대 까지 방향 생성 후 업데이트
    for (int i = 0; i < g; i++)
    {
        int size = direction.size();
        for (int j = size - 1; j >= 0; --j) // 뒤에 붙이기 때문에 list의 마지막(size-1)부터 읽어야
        {
            direction.push_back((direction[j] + 1) % 4); // -90도 회전 후 추가
        }
    }

    // 2. board 업데이트
    board[y][x] = 1;          // 세로: [y], 가로: [x]
    for (int dir : direction) // directions = [0,1,2] 동0북1서2남3
    {
        x += dx[dir];
        y += dy[dir];
        board[y][x] = 1; // 선분의 끝점을 1로 설정
    }
}

int countsquare()
{
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) // 네 꼭짓점이 포함되면
                count++;
        }
    }
    return count;
}

// 우리의 목표는 네 꼭짓점이 모두 드래곤커프의 일부인 것의 갯수
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawdragoncurve(x, y, d, g);
    }

    cout << countsquare() << endl;
    return 0;
}