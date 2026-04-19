#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    int cost[26][26][4];
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            for(int k=0; k<4; k++){
                cost[i][j][k] = INT_MAX;
            }
        }
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    loadInfo start;
    start.r = 0; start.c = 0; start.dir = 4; start.cost = 0;
    q.push(start);
    for(int i=0; i<4; i++){
        cost[0][0][i] = 0;
    }
    

    while(!q.empty()){
        loadInfo node = q.front(); q.pop();
        if(node.r == board.size()-1 && node.c == board.size()-1){
            answer = *min_element(cost[node.r][node.c], cost[node.r][node.c] + 4);
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
            
            if(next.cost <= cost[nr][nc][i]){
                cost[nr][nc][i] = next.cost;
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