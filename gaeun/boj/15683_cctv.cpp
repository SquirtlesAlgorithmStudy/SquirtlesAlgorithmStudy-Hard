#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, M;
int grid[9][9];
vector<pair<int, int>> cctv;
vector<vector<int>> cctvDir(8);
int result = INT_MAX;

void check_cctv(pair<int, int> cctv, string dir){
    // 상
    if(dir == "up"){
        for(int r=cctv.first-1; r>=0; r--){
            if(grid[r][cctv.second]==6) break;
            else if(grid[r][cctv.second]==0) grid[r][cctv.second] = -1;
            else continue;
        }
    }
    
    // 하
    else if(dir == "down"){
        for(int r=cctv.first+1; r<N; r++){
            if(grid[r][cctv.second]==6) break;
            else if(grid[r][cctv.second]==0) grid[r][cctv.second] = -1;
            else continue;
        }
    }
    
    // 좌
    else if(dir == "left"){
        for(int c=cctv.second-1; c>=0; c--){
            if(grid[cctv.first][c]==6) break;
            else if(grid[cctv.first][c]==0) grid[cctv.first][c] = -1;
            else continue;
        }
    }
    
    // 우
    else if(dir == "right"){
        for(int c=cctv.second+1; c<M; c++){
            if(grid[cctv.first][c]==6) break;
            else if(grid[cctv.first][c]==0) grid[cctv.first][c] = -1;
            else continue;
        }
    }    
}

void change_grid(int cctvType, int dirCase, pair<int, int> cctv){
    if(cctvType == 1){
        switch(dirCase){
            case 1:
                check_cctv(cctv, "up");                
                break;
            case 2:
                check_cctv(cctv, "down");
                break;
            case 3:
                check_cctv(cctv, "left");
                break;
            case 4:
                check_cctv(cctv, "right");
        }
    }
    else if(cctvType == 2){
        switch(dirCase){
            case 1:
                check_cctv(cctv, "up");
                check_cctv(cctv, "down");
                break;
            case 2:
                check_cctv(cctv, "left");
                check_cctv(cctv, "right");
                break;
        }
    }
    else if(cctvType == 3){
        switch(dirCase){
            case 1:
                check_cctv(cctv, "up");
                check_cctv(cctv, "left");
                break;
            case 2:
                check_cctv(cctv, "up");
                check_cctv(cctv, "right");
                break;
            case 3:
                check_cctv(cctv, "down");
                check_cctv(cctv, "left");
                break;
            case 4:
                check_cctv(cctv, "down");
                check_cctv(cctv, "right");
        }
    }
    else if(cctvType == 4){
        switch(dirCase){
            case 1:
                check_cctv(cctv, "down");
                check_cctv(cctv, "left");
                check_cctv(cctv, "right");
                break;
            case 2:
                check_cctv(cctv, "up");
                check_cctv(cctv, "left");
                check_cctv(cctv, "right");
                break;
            case 3:
                check_cctv(cctv, "up");
                check_cctv(cctv, "down");
                check_cctv(cctv, "right");
                break;
            case 4:
                check_cctv(cctv, "up");
                check_cctv(cctv, "down");
                check_cctv(cctv, "left");
        }
    }
    else if(cctvType == 5){
        switch(dirCase){
            case 1:
                check_cctv(cctv, "up");
                check_cctv(cctv, "down");
                check_cctv(cctv, "left");
                check_cctv(cctv, "right");
        }
    }
}

int count_zero(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void dfs(int idx){
    if(idx == cctv.size()){
        result = min(result, count_zero());
        return;
    }
    else{
        for(int i=0; i<cctvDir[idx].size(); i++){
            int orig[9][9];
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    orig[i][j] = grid[i][j];
                }
            }
            change_grid(orig[cctv[idx].first][cctv[idx].second], cctvDir[idx][i], cctv[idx]);
            dfs(idx+1);
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    grid[i][j] = orig[i][j];
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;

    int idx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
            
            if(grid[i][j] == 1 || grid[i][j] == 3 || grid[i][j] == 4){
                cctv.push_back({i, j});
                cctvDir[idx].push_back(1);
                cctvDir[idx].push_back(2);
                cctvDir[idx].push_back(3);
                cctvDir[idx].push_back(4);
                idx++;
            }
            else if(grid[i][j] == 2){
                cctv.push_back({i, j});
                cctvDir[idx].push_back(1);
                cctvDir[idx].push_back(2);
                idx++;
            }
            else if(grid[i][j] == 5){
                cctv.push_back({i, j});
                cctvDir[idx].push_back(1);
                idx++;
            }
        }
    }

    dfs(0);

    cout << result << endl;
}