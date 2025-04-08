#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

int N, M;
int grid[50][50];
vector<pair<int, int>> virus;
vector<pair<int, int>> selected;
vector<vector<int>> spread(50, vector<int>(50));
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int minTime = INT_MAX;

void bfs(pair<int, int> node){
    bool visited[50][50] = {0,};
    queue<pair<int, int>> q;
    q.push(node);
    visited[node.first][node.second] = 1;
    spread[node.first][node.second] = 0;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
            if(visited[nr][nc]) continue;
            if(grid[nr][nc] == 1) continue;

            if(spread[nr][nc] == -2) spread[nr][nc] = INT_MAX; // 비활 바이러스 타고 넘어갈 수 있게. 
            spread[nr][nc] = min(spread[nr][nc], spread[curr.first][curr.second]+1);
            q.push({nr,nc});
            visited[nr][nc] = 1;
        }
    }
    
}

void comb(int s_i, int depth){
    if(depth == M){
        vector<vector<int>> tmp = spread;

        // 활성 바이러스 자리는 0으로
        for(int i=0; i<selected.size(); i++){
            spread[selected[i].first][selected[i].second] = 0;
        }
        for(int i=0; i<selected.size(); i++){
            bfs(selected[i]);
        }
        // 비활성 바이러스 자리는 다시 -2로
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(grid[r][c] == 2 && spread[r][c] != 0){
                    spread[r][c] = -2;
                }
            }
        }
    
        int maxTime = spread[0][0];
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                maxTime = max(maxTime, spread[r][c]);
            }
        }
        minTime = min(minTime, maxTime);

        // backtracking을 위해
        spread = tmp;
        return;
    }
    else{
        for(int i=s_i; i<virus.size(); i++){
            selected.push_back(virus[i]);
            comb(i+1, depth+1);
            selected.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 0) spread[i][j] = INT_MAX;
            if(grid[i][j] == 1) spread[i][j] = -1;
            if(grid[i][j] == 2) { virus.push_back({i, j}); spread[i][j] = -2;}
        }
    }

    comb(0,0);

    if(minTime == INT_MAX) cout << -1 << "\n";
    else cout << minTime << "\n";

}