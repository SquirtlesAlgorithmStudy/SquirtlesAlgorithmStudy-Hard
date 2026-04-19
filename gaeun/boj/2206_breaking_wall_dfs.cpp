// dfs로 완탐 -> 시간초과(4^(N*M))

#include <iostream>
#include <climits>
#include <string>

using namespace std;

int ans = INT_MAX;
int map[1001][1001] = {0,};
int visited[1001][1001] = {0,};
int dr[4] = {-1, 1, 0, 0}; // 상하좌우
int dc[4] = {0, 0, -1, 1};
int N, M;

void dfs(int r, int c, bool isBreakPossible, int dist){
    //cout << "r: " << r << ", c: " << c << ", isBreakPossible: " << isBreakPossible << ", dist: " << dist << endl;

    visited[r][c] = 1;
    if(r==N && c==M){
        ans = min(ans, dist);
    } 

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<=0 || nr>N || nc<=0 || nc>M) continue;
        if(visited[nr][nc]) continue;

        if(map[nr][nc] == 1){
            if(map[nr+dr[i]][nc+dc[i]]==0 && isBreakPossible==1){
                dfs(nr, nc, 0, dist+1);
                visited[nr][nc] = 0;
            } 
            else continue;
        }
        else{
            dfs(nr, nc, isBreakPossible, dist+1);
            visited[nr][nc] = 0;
        } 
    }
}

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
        for(int j=1; j<=M; j++){
            map[i][j] = s[j-1] - '0';
        }
    }

    dfs(1,1,1,1);

    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}