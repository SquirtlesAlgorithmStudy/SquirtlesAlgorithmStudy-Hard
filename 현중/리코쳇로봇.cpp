// 프로그래머스 리코쳇 로봇

#include <iostream>
#include <vector>
#include <queue>
#include <tuple> //값이 고정이고 복사할 때 조심할 필요 없음 LIST와 비교!!!!
#include <set>

using namespace std;

int solution(vector<string> board)
{
    int n = board.size();
    int m = board[0].size();

    // 시작점 : R, 끝점 : G
    int startX, startY, endX, endY;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
            if (board[i][j] == 'G')
            {
                endX = i;
                endY = j;
            }
        }
    }
    // 상하좌우
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<pair<int, int>, int>> q; // {{x, y}, 이동 횟수}
    set<pair<int, int>> visited;
    q.push({{startX, startY}, 0});
    visited.insert({startX, startY});

    while (!q.empty())
    {
        auto [current, moves] = q.front();
        auto [cx, cy] = current;
        q.pop();

        if (cx == endX && cy == endY)
        {
            return moves;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cx;
            int ny = cy;

            while (nx + dx[i] >= 0 && nx + dx[i] < n && ny + dy[i] >= 0 && ny + dy[i] < m && board[nx + dx[i]][ny + dy[i]] != 'D')
            {
                nx += dx[i];
                ny += dy[i];
            }
            // 방문하지 않았다면, queue에 추가
            if (visited.find({nx, ny}) == visited.end())
            {
                visited.insert({nx, ny});
                q.push({{nx, ny}, moves + 1});
            }
        }
    }
    return -1; // BFS 종료 후 목표 지점에 도달하지 못하면 -1
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> board(n);

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    cout << solution(board) << endl;
    return 0;
}
