#include <iostream>

using namespace std;

int grid[500][500];
int visited[500][500] = {0,};    
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int N, M;
int result=0;

void dfs(int r, int c, int depth, int sum){
    visited[r][c] = 1;
    if(depth == 4){
        result = max(result, sum);
    }
    else{
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(visited[nr][nc]==1) continue;
            dfs(nr, nc, depth+1, sum+grid[nr][nc]);
            visited[nr][nc] = 0; // for backtracking
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
        }
    }

    // brute force for tetromino except ㅗ and its variations
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            dfs(i,j,1,grid[i][j]);
            visited[i][j] = 0;
        }
    }

    // brute force for ㅗ and its variations
    int sum = 0;
    for(int i=0; i+2<N; i++){
        for(int j=0; j+1<M; j++){
            sum = grid[i][j] + grid[i+1][j] + grid[i+2][j] + grid[i+1][j+1];
            result = max(result, sum);

            sum = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] + grid[i+1][j];
            result = max(result, sum);
        }
    }

    for(int i=0; i+1<N; i++){
        for(int j=0; j+2<M; j++){
            sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1];
            result = max(result, sum);

            sum = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] + grid[i][j+1];
            result = max(result, sum);
        }
    }

    cout << result << endl;
    
}