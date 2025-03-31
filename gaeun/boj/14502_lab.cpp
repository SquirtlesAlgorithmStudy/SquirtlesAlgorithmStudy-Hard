#include <iostream>
#include <queue>
using namespace std;

int N, M;
int grid[8][8];
int newGrid[8][8];
queue<pair<int,int>> virus;
int safe = 0;
int result = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(){
    // queue와 grid 복사해서 써야하는거 잊지 말기!!
    queue<pair<int,int>> q = virus;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            newGrid[i][j] = grid[i][j];
        }
    }

    // spread a virus
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            pair<int,int> next;
            next.first = curr.first + dr[i];
            next.second = curr.second + dc[i];

            if(newGrid[next.first][next.second] == 0 && (next.first >= 0 && next.first < N && next.second >= 0 && next.second < M)){
                newGrid[next.first][next.second] = 2;
                q.push(next);
            }
        }
    }

    // check the number of safety region
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(newGrid[i][j] == 0){
                safe++;
            }
        }
    }
    result = max(result, safe);
    safe = 0;
}   

// N*M에서 3개의 순열을 찾는 경우의 수. 즉, N*M_P_3
void wall_recur(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    else{
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j] == 0){
                    grid[i][j] = 1;
                    wall_recur(cnt+1);
                    grid[i][j] = 0;
                }
            }
        }
    }
}

void wall_for() // N*M에서 3개의 조합을 찾는 경우의 수. 즉, N*M_C_3
{
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] == 0){
                grid[i][j] = 1;
                for(int a=0; a<N; a++){
                    for(int b=0; b<M; b++){
                        if(grid[a][b] == 0 && ((a>i) || (a==i && b>j))){
                            grid[a][b] = 1;
                            for(int p=0; p<N; p++){
                                for(int q=0; q<M; q++){
                                    if(grid[p][q] == 0 && ((p>a) || (p==a && q>b))){
                                        grid[p][q] = 1;
                                        bfs();
                                        grid[p][q] = 0;
                                    }
                                }
                            }
                            grid[a][b] = 0;
                        }
                    }
                }
                grid[i][j] = 0;
            }
        }
    }
}

int main(){

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2) virus.push({i,j});
        }
    }

    //wall_recur(0);
    wall_for();
    cout << result << endl;

}