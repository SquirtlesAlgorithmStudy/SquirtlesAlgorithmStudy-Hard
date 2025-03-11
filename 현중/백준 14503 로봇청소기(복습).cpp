// 백준 14503 로봇청소기(복습)

// 목표 : 청소한 칸 수

#include <iostream>
#include <vector>

using namespace std;

int N, M;                 // 방 크기
int r, c, dir;            // 로봇의 처음 좌표, 방향(북 동 남 서)
vector<vector<int>> room; // 격자의 내용 보다는 방 전체에 관심이 있기 때문에 <int> 한개
vector<vector<bool>> clean;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int turn_left(int dir)
{
    return (dir + 3) % 4;
}

int clean_room_bfs()
{

    int count = 0;
    bool done = false;
    while (!done)
    { // 1. 현재 위치가 청소되지 않았으면 청소
        if (!clean[r][c])
        {
            clean[r][c] = true;
            count++;
        }

        bool found_next = false;
        for (int i = 0; i < 4; ++i)
        { // 2. 4방향을 확인하며 청소 가능한 곳 탐색
            dir = turn_left(dir);
            int nx = r + dx[dir];
            int ny = c + dy[dir];

            // 3. 청소가 가능하면 이동
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && room[nx][ny] == 0 && !clean[nx][ny])
            {
                r = nx;
                c = ny;
                found_next = true;
                break;
            }
        }
        // 4. 청소할 곳이 없으면 후진
        if (!found_next)
        {
            int back_dir = (dir + 2) % 4;
            int bx = r + dx[back_dir];
            int by = c + dy[back_dir];

            if (room[bx][by] == 1)
            {
                done = true;
            }
            else
            {
                r = bx;
                c = by;
            }
        }
    }

    return count;
}

int main()
{
    cin >> N >> M;
    cin >> r >> c >> dir;

    room.resize(N, vector<int>(M));
    clean.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }

    cout << clean_room_bfs() << endl;

    return 0;
}
