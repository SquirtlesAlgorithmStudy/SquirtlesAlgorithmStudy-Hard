#include <iostream>
#include <vector>

using namespace std;

int R, C, T;    
vector<vector<int>> grid;
vector<int> machine;

void spread(){
    vector<vector<int>> tmp = grid;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for(int r=1; r<=R; r++){
        for(int c=1; c<=C; c++){
            if(grid[r][c] > 0){
                int dirCnt = 0;
                for(int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr<1 || nr>R || nc<1 || nc>C) continue;
                    if(grid[nr][nc] == -1) continue;

                    dirCnt++;
                }

                int add = grid[r][c] / 5;
                tmp[r][c] = tmp[r][c] - add*dirCnt;

                for(int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr<1 || nr>R || nc<1 || nc>C) continue;
                    if(grid[nr][nc] == -1) continue;

                    tmp[nr][nc] += add;

                    // cout << "node (" << r << "," << c << "): " << "\n";
                    // cout << "dirCnt: " << dirCnt << ", add: " << add << "\n" << "tmp: " << "\n";
                    // for(int i=1; i<=R; i++){
                    //     for(int c=1; c<=C; c++){
                    //         cout << tmp[i][c] << " ";
                    //     }
                    //     cout << "\n";
                    // }
                    // cout << "\n";

                }
            }
        }
    }
    grid = tmp;
}

void blow(){
    int head, tail;
    head = machine[0]; tail = machine[1];

    // 윗쪽바람부터
    for(int r=head-2; r>=1; r--){ // 공기청정기로 내려가는 먼지들
        grid[r+1][1] = grid[r][1];
    }
    for(int c=2; c<=C; c++){ // 1행에서 왼쪽으로 이동하는 먼지들
        grid[1][c-1] = grid[1][c];
    }
    for(int r=2; r<=head; r++){ // 위쪽으로 올라가는 먼지들
        grid[r-1][C] = grid[r][C];
    }
    for(int c=C-1; c>=2; c--){ // 오른쪽으로 이동하는 먼지들
        grid[head][c+1] = grid[head][c];
    }
    grid[head][2] = 0;

    // 아랫쪽 바람
    for(int r=tail+2; r<=R; r++){ // 공기청정기로 올라가는 먼지들
        grid[r-1][1] = grid[r][1];
    }
    for(int c=2; c<=C; c++){ // 왼쪽으로 이동하는 먼지들
        grid[R][c-1] = grid[R][c];
    }
    for(int r=R-1; r>=tail; r--){ // 아래로 내려가는 먼지들
        grid[r+1][C] = grid[r][C];
    }
    for(int c=C-1; c>=2; c--){ // 오른쪽으로 움직이는 먼지들
        grid[tail][c+1] = grid[tail][c];
    }
    grid[tail][2] = 0;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> R >> C >> T;
    grid.resize(R+1,vector<int>(C+1));

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == -1) machine.push_back(i);
        }
    }

    for(int i=0; i<T; i++){
        spread();
        blow();
    }

    int sum = 0;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(grid[i][j] > 0) sum += grid[i][j];
        }
    }

    cout << sum << "\n";
    

    // cout << "\n";
    // for(int i=1; i<=R; i++){
    //     for(int j=1; j<=C; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

//
// 7 8 10
// 0 0 0 0 0 0 1 8
// 0 0 1 0 3 0 5 6
// -1 2 1 1 0 4 6 5
// -1 5 2 0 0 2 12 0
// 0 1 1 0 5 10 13 8
// 0 1 9 4 3 5 12 0
// 0 8 17 8 3 4 8 4