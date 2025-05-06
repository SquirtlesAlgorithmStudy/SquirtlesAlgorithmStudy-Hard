#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct loadInfo{
    int r,c;
    int dir;
    int cost;
};

int bfs(vector<vector<int>> board){
    int answer = INT_MAX;
    queue<loadInfo> q;
    vector<vector<int>> cost;
    cost.assign(board.size(), vector<int>(board.size(), INT_MAX));
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    loadInfo start;
    start.r = 0; start.c = 0; start.dir = 4; start.cost = 0;
    q.push(start);
    cost[0][0] = 0;

    while(!q.empty()){
        loadInfo node = q.front(); q.pop();
        if(node.r == board.size()-1 && node.c == board.size()-1){
            answer = min(answer, node.cost);
        }

        for(int i=0; i<4; i++){
            int nr = node.r + dr[i];
            int nc = node.c + dc[i];

            if(nr<0 || nr>=board.size() || nc<0 || nc>=board.size()) continue;
            if(board[nr][nc]) continue;

            loadInfo next;
            next.r = nr; next.c = nc; next.dir = i;
            if(node.dir == i || node.dir == 4) next.cost = node.cost + 100; // 이전 노드가 (0,0)이거나, 방향이 유지된다면 직선 도로
            else next.cost = node.cost + 600; // 코너 + 직선도로 필요
            
            if(next.cost <= cost[nr][nc]){
                cost[nr][nc] = next.cost;
                q.push(next);
            }
        }
    }

    return answer;
}

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;

    answer = bfs(board);

    return answer;
}