// 백준 14499 주사위 굴리기(복습)

#include <iostream>
#include <vector>

using namespace std;

int dice[6] = {}; // 상0하1좌2우3앞4뒤5

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int N, M;    // 가로, 세로
int x, y, K; // 주사위 초기위치, 명령갯수
vector<vector<int>> board;

void rolldice(int direction)
{
    int temp[6];
    for (int i = 0; i < 6; ++i)
    {
        temp[i] = dice[i];
    }
    // 상0 하1 좌2 우3 앞4 뒤5
    if (direction == 1)
    { // dir == 1 동
        dice[0] = temp[2];
        dice[2] = temp[1];
        dice[1] = temp[3];
        dice[3] = temp[0];
    }

    if (direction == 2)
    { // dir == 2 서
        dice[2] = temp[0];
        dice[1] = temp[2];
        dice[3] = temp[1];
        dice[0] = temp[3];
    }

    if (direction == 3)
    { // dir == 3 북
        dice[5] = temp[0];
        dice[1] = temp[5];
        dice[4] = temp[1];
        dice[0] = temp[4];
    }

    if (direction == 4)
    { // dir == 4 남
        dice[4] = temp[0];
        dice[1] = temp[4];
        dice[5] = temp[1];
        dice[0] = temp[5];
    }
}

int main()
{

    cin >> N >> M >> x >> y >> K;

    board.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<int> command(K);
    for (int i = 0; i < K; i++)
    {
        cin >> command[i];
    }

    for (int i = 0; i < K; i++)
    {
        int dir = command[i];
        int nx = x + dx[dir - 1];
        int ny = y + dy[dir - 1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        {
            continue;
        }

        rolldice(dir);

        x = nx;
        y = ny;

        if (board[x][y] == 0)
        {
            board[x][y] = dice[1];
        }
        else
        {
            dice[1] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[0] << endl;
    }
    return 0;
}