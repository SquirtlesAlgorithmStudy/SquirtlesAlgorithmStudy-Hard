#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int grid[10][10];
bool visited[10][10] = {0,};
int answer = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c){
    visited[r][c] = 1;
    for(int i=0; i<4; i++){
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(grid[nr][nc] == 0 && visited[nr][nc] == 0){
            visited[nr][nc] = 1;
            grid[nr][nc] = 2;
            dfs(nr, nc);
        }
    }
}

void spread_virus(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] == 2 && visited[i][j] == 0){
                dfs(i,j);
            }
        }
    }
}

int count_safe(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void comb(int s_i, int s_j, int depth){
    if(depth >= 3){
        int tmp[10][10];
        memcpy(tmp, grid, sizeof(grid));
        memset(visited,0,sizeof(visited));
        spread_virus();
        int val = count_safe();
        answer = max(answer, val);
        memcpy(grid, tmp, sizeof(tmp));
    }
    else{
        for(int i=s_i; i<N; i++){
            int j = (i==s_i) ? s_j : 0;
            for(; j<M; j++){
                if(grid[i][j]==0){
                    grid[i][j] = 1;
                    comb(i,j+1,depth+1);
                    grid[i][j] = 0;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
        }
    }

    comb(0, 0, 0);

    cout << answer << "\n";
}