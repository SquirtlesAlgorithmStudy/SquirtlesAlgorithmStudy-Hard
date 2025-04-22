#include <iostream>
#include <vector>

using namespace std;

int M, N;
int grid[501][501];
int dp[501][501];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int r, int c){
    if(r == M-1 && c == N-1) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    dp[r][c] = 0;

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0 || nr>=M || nc<0 || nc>=N) continue;
        if(grid[nr][nc] < grid[r][c]) dp[r][c] += dfs(nr,nc);
    }
    return dp[r][c];
}

int main(){
    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0,0) << "\n";

}