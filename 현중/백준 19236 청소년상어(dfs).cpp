// 백준 19236 청소년상어

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 물고기 구조체
struct Fish
{                  // 구조체를 사용하는 이유는 더 효율적으로 관리하기 위해
    int x, y, dir; // 물고기의 x,y좌표 / 방향 / 번호
    bool alive;    // 물고기 살아있는지 여부
};

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 8방향: ↑, ↖, ←, ↙, ↓, ↘, →, ↗
const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1}; // 8방향에 대한 y 좌표 이동

int maxSum = 0;

// 2. 물고기 이동
void moveFish(vector<vector<int>> &board, vector<Fish> &fishes, int sx, int sy)
{
    for (int i = 1; i <= 16; ++i) // 물고기 갯수
    {
        if (!fishes[i].alive) // 1. 죽었어? 끝
            continue;

        int x = fishes[i].x; // 2. 입력받아
        int y = fishes[i].y;
        int dir = fishes[i].dir;

        for (int j = 0; j < 8; ++j) // 3. 이동방향
        {
            int ndir = (dir + j) % 8;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && !(nx == sx && ny == sy)) // 3.1 범위 안
            {
                if (board[nx][ny] != -1) // 3.1.1 갈수 있? => swap
                {
                    int target = board[nx][ny];
                    swap(fishes[i].x, fishes[target].x);
                    swap(fishes[i].y, fishes[target].y);
                    swap(board[x][y], board[nx][ny]);
                }
                else // 3.1.2 갈수 없? => 그대로
                {
                    fishes[i].x = nx;
                    fishes[i].y = ny;
                    board[nx][ny] = i;
                    board[x][y] = -1;
                }
                fishes[i].dir = ndir;
                break;
            }
        }
    }
}

// 2.1 새로운 위치가 상어x, 범위 내
void dfs(vector<vector<int>> board, vector<Fish> fishes, int sx, int sy, int sum)
{
    int fishNum = board[sx][sy];        // 현재 상어가 있는 위치의 물고기 번호
    int sharkDir = fishes[fishNum].dir; // 상어가 이동할 방향 = 먹은 물고기 방향
    fishes[fishNum].alive = false;      // 물고기를 먹었음으로 die
    board[sx][sy] = -1;                 // board update
    sum += fishNum;                     // 현재 물고기 번호 합산
    maxSum = max(maxSum, sum);

    moveFish(board, fishes, sx, sy); // 물고기 이동 처리

    for (int step = 1; step < 4; ++step) // 상어가 이동할 수 있는 모든 경로 탐색
    {
        int nx = sx + dx[sharkDir] * step; // * 상어가 몇칸 이동할 건지
        int ny = sy + dy[sharkDir] * step;

        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && board[nx][ny] != -1)
        {
            vector<vector<int>> newBoard = board;
            vector<Fish> newFishes = fishes;
            dfs(newBoard, newFishes, nx, ny, sum);
        }
    }
}
int main()
{
    vector<vector<int>> board(4, vector<int>(4));
    vector<Fish> fishes(17); // vector을 [0~16]까지 17마리 만들고 실제로는 1~16까지 사용

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int a, b;
            cin >> a >> b;
            board[i][j] = a;
            fishes[a] = {i, j, b - 1, true};
        }
    }

    dfs(board, fishes, 0, 0, 0);

    cout << maxSum << endl;

    return 0;
}