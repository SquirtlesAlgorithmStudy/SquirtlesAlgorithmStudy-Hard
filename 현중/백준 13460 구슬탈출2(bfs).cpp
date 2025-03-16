// 구슬탈출2

// 최단경로 BFS

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
char board[10][10];
bool visited[10][10][10][10];

// 1. R구슬의 위치, B구슬의 위치, 움직인 횟수
struct State
{
    int rx, ry, bx, by, move;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 2. 구슬을 이동시키는 함수
pair<int, int> move(int x, int y, int dx, int dy)
{
    int count = 0;
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O')
    { // 2.1 벽이 아닌지 확인 && 구멍에 빠지면 움직일 수 없음
        x += dx;
        y += dy;
        count++;
    }
    return {x, y};
}

int bfs(int rx, int ry, int bx, int by)
{
    queue<State> q; // struct의 {rx,ry,bx,by,move} 묶어서 저장
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!q.empty())
    { // queue(탐색상태)가 남지 않는 한 계속
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int moves = q.front().move;
        q.pop();

        if (moves >= 10)
            return -1; // 10번 넘어가면 -1출력

        // 4방향 이동
        for (int i = 0; i < 4; ++i)
        {
            auto [nrx, nry] = move(rx, ry, dx[i], dy[i]);
            auto [nbx, nby] = move(bx, by, dx[i], dy[i]);

            // 파란구슬 빠지면 실패
            if (board[nbx][nby] == 'O')
                continue;

            // 빨간구슬 빠지면 성공
            if (board[nrx][nry] == 'O')
                return moves + 1; // 적어도 1번은 움직여야함으로

            // 두 구슬이 같은 위치에 있는 경우, 더 많이 움직인 구슬을 한칸 뒤로 이동!  ex) o b r #
            if (nrx == nbx && nry == nby)
            {
                if (abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by))
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            // 중복된 부분은 다시 탐색하지 않기 위해
            if (!visited[nrx][nry][nbx][nby])
            {                                            // 방문안했어?
                visited[nrx][nry][nbx][nby] = true;      // 방문처리
                q.push({nrx, nry, nbx, nby, moves + 1}); // 새로운 상태를 queue에 저장
            }
        }
    }

    return -1; // 10번 이하로 해결하지 못하면 실패
}

int main()
{
    cin >> N >> M;
    int rx, ry, bx, by;

    // 보드 생성
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            else if (board[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    cout << bfs(rx, ry, bx, by) << endl;

    return 0;
}
