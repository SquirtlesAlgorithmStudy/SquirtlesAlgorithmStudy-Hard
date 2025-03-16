#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int testcase;
int w, h; // N,M
char building[1001][1001];
bool visited[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Point
{
    int x, y;
};

// BFS로 불과 사람의 이동을 처리
int bfs(queue<Point> &fireQueue, queue<Point> &personQueue)
{
    int time = 0;
    while (!personQueue.empty())
    {                                    // 목표 : 사람이 탈출하는데 가장 빠른 시간 출력
        int fireSize = fireQueue.size(); // 불의 크기를 파악하기 위해 현재 불의 크기, queue size를 미리 저장
        // 불의 확산 처리
        for (int i = 0; i < fireSize; ++i)
        {
            Point fire = fireQueue.front(); // 맨앞의 불 좌표를 가져옴
            fireQueue.pop();
            for (int j = 0; j < 4; ++j)
            {
                int nx = fire.x + dx[j];
                int ny = fire.y + dy[j];
                if (nx >= 0 && ny >= 0 && nx < h && ny < w && building[nx][ny] == '.')
                {
                    building[nx][ny] = '*';
                    fireQueue.push({nx, ny});
                }
            }
        }

        int personSize = personQueue.size();
        // 사람의 이동 처리
        for (int i = 0; i < personSize; ++i)
        {
            Point person = personQueue.front();
            personQueue.pop();
            for (int j = 0; j < 4; ++j)
            {
                int nx = person.x + dx[j];
                int ny = person.y + dy[j];
                // 탈출 조건
                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                {
                    return time + 1;
                }
                if (building[nx][ny] == '.' && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    personQueue.push({nx, ny});
                }
            }
        }
        time++;
    }
    return -1; // 탈출 불가능한 경우
}

int main()
{
    cin >> testcase;
    while (testcase--)
    { // 종료조건을 명확하게 하기위해, 모든 testcase를 돌리기 위해
        cin >> w >> h;
        queue<Point> fireQueue;
        queue<Point> personQueue;

        // 건물 초기화 및 입력 받기
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> building[i][j];
                visited[i][j] = false;
                if (building[i][j] == '*')
                {
                    fireQueue.push({i, j}); // queue : push / vector : push_back
                }
                else if (building[i][j] == '@')
                {
                    personQueue.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int result = bfs(fireQueue, personQueue);
        if (result == -1)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }
    return 0;
}