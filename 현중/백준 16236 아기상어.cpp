// 백준 16236 아기상어

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Position
{
    int x, y, dist;
};

// 상좌우하
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int N;
vector<vector<int>> board;
Position shark;                   // 아기상어의 위치와 거리정보
int sharkSize = 2, eatenFish = 0; // 상어 초기 크기와 먹은 물고기 수
int totalTime = 0;

Position bfs(Position start)
{
    queue<Position> q;
    // visited = [[false, false, false],[],[]] / 만약 vector<vector<bool>> visited(N, false))면 visited = [false, false, false]
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    q.push(start);
    visited[start.x][start.y] = true;

    // 먹을 수 있는 물고기 list저장
    vector<Position> fishList;
    // 가장 가까운 거리(초기 = -1)
    int minDist = -1;

    while (!q.empty())
    {
        Position current = q.front();
        q.pop();

        // 현재 위치에서 먹을 수 ?
        if (board[current.x][current.y] > 0 && board[current.x][current.y] < sharkSize)
        {
            // 1. 가장 가까운 거리에 있거나, 현재 위치에 있을 때
            if (minDist == -1 || current.dist == minDist)
            {
                fishList.push_back(current); // 물고기 list 맨 뒤에 넣고
                minDist = current.dist;      // 최소거리를 갱신
            }
            // 만약 더 가까운 물고기를 찾을경우
            else if (current.dist < minDist)
            {
                fishList.clear();            // 기존 물고기 리스트를 초기화
                fishList.push_back(current); // 새로운 물고기 추가
                minDist = current.dist;      // 최소 거리 갱신
            }
        }

        // 상하좌우 탐색
        for (int i = 0; i < 4; ++i)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && board[nx][ny] <= sharkSize)
            {
                visited[nx][ny] = true;
                q.push({nx, ny, current.dist + 1});
            }
        }
    }

    // 만약 먹을 수 있는 물고기가 없으면
    if (fishList.empty())
    {
        return {-1, -1, -1};
    }

    // 만약 가까운 물고기가 많다면, 가장 위, 가장 왼
    sort(fishList.begin(), fishList.end(), [](Position a, Position b)
         {
        if(a.x == b.x) return a.y < b.y; // 같은 행이면 왼쪽이 우선
        return a.x < b.x; });
    return fishList[0]; // 가장 가까운 물고기 반환
}

int main()
{
    cin >> N;
    board.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                shark = {i, j, 0}; // x,y,dist
                board[i][j] = 0;   // 그 이후에 빈칸으로 처리하기 위해
            }
        }
    }

    while (true)
    {
        // 1. 먹을 수 있는 물고기 찾기
        Position target = bfs(shark);
        if (target.x == -1)
            break;

        // 2. 물고기 먹고 시간 계산
        totalTime += target.dist;
        eatenFish++;
        // 먹은 칸은 빈칸으로 변경
        board[target.x][target.y] = 0;
        shark = {target.x, target.y, 0};

        // 3. 크기 증가 조건
        if (eatenFish == sharkSize)
        {
            sharkSize++;
            eatenFish = 0;
        }
    }

    cout << totalTime << endl;

    return 0;
}