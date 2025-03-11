// 백준 14503 로봇청소기

#include <iostream>
#include <vector>

using namespace std;

int N, M, r, c, dir;
vector<vector<int>> room;
vector<vector<bool>> clean;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int turn_left(int dir)
{
    return (dir + 3) % 4;
}

int clean_room()
{
    int count = 0;
    bool done = false;

    while (!done)
    {
        if (!clean[r][c])
        {
            clean[r][c] = true;
            count++;
        }

        bool found_next = false;

        for (int i = 0; i < 4; ++i)
        {
            dir = turn_left(dir);
            int nx = r + dx[dir];
            int ny = c + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && room[nx][ny] == 0 && !clean[nx][ny])
            {
                r = nx;
                c = ny;
                found_next = true;
                break;
            }
        }

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

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> room[i][j];
        }
    }

    cout << clean_room() << endl;

    return 0;
}