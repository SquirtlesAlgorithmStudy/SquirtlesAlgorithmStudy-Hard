#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, M;
int grid[9][9];
vector<pair<int,int>> cctvCase[8][4];
int result = INT_MAX;

void check_cctv(pair<int, int> cctv, string dir, int cctvIdx, int cctvDir){
    // 상
    if(dir == "up"){
        for(int r=cctv.first-1; r>=0; r--){
            if(grid[r][cctv.second]==6) break;
            else if(grid[r][cctv.second]==0) cctvCase[cctvIdx][cctvDir].push_back({r,cctv.second});
            else continue;
        }
    }
    
    // 하
    else if(dir == "down"){
        for(int r=cctv.first+1; r<N; r++){
            if(grid[r][cctv.second]==6) break;
            else if(grid[r][cctv.second]==0) cctvCase[cctvIdx][cctvDir].push_back({r,cctv.second});
            else continue;
        }
    }
    
    // 좌
    else if(dir == "left"){
        for(int c=cctv.second-1; c>=0; c--){
            if(grid[cctv.first][c]==6) break;
            else if(grid[cctv.first][c]==0) cctvCase[cctvIdx][cctvDir].push_back({cctv.first,c});
            else continue;
        }
    }
    
    // 우
    else if(dir == "right"){
        for(int c=cctv.second+1; c<M; c++){
            if(grid[cctv.first][c]==6) break;
            else if(grid[cctv.first][c]==0) cctvCase[cctvIdx][cctvDir].push_back({cctv.first,c});
            else continue;
        }
    }    
}

void permutation(int idx){
    if(idx==sizeof(cctvCase)){
        // 0 개수 count
    }
    else{
        for(int i=0; i<sizeof(cctvCase[idx]); i++){
            // int orig[8][8]; orig에 grid 저장하기
            // cctvCase[cctvIdx][cctvDir]에 저장되어있는 모든 좌표들을 #으로 바꾸기
            permutation(idx+1);
            // backtracking을 위해 orig 복원: grid에 orig 넣어주기 
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

    int idx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j]==1){
                check_cctv({i,j},"up",idx,0);
                check_cctv({i,j},"down",idx,1);
                check_cctv({i,j},"left",idx,2);
                check_cctv({i,j},"right",idx,3);
                idx++;
            }
            else if(grid[i][j]==2){
                check_cctv({i,j},"up",idx,0);
                check_cctv({i,j},"down",idx,0);
                check_cctv({i,j},"left",idx,1);
                check_cctv({i,j},"right",idx,1);
                idx++;
            }
            else if(grid[i][j]==3){
                check_cctv({i,j},"up",idx,0);
                check_cctv({i,j},"right",idx,0);

                check_cctv({i,j},"up",idx,1);
                check_cctv({i,j},"left",idx,1);

                check_cctv({i,j},"down",idx,2);
                check_cctv({i,j},"right",idx,2);

                check_cctv({i,j},"down",idx,3);
                check_cctv({i,j},"left",idx,3);
            }
            else if(grid[i][j]==4){
                check_cctv({i,j},"up",idx,0);
                check_cctv({i,j},"down",idx,0);
                check_cctv({i,j},"left",idx,0);

                check_cctv({i,j},"up",idx,1);
                check_cctv({i,j},"right",idx,1);
                check_cctv({i,j},"left",idx,1);

                check_cctv({i,j},"up",idx,2);
                check_cctv({i,j},"down",idx,2);
                check_cctv({i,j},"right",idx,2);

                check_cctv({i,j},"right",idx,3);
                check_cctv({i,j},"down",idx,3);
                check_cctv({i,j},"left",idx,3);
                idx++;                
            }
            else if(grid[i][j]==5){
                check_cctv({i,j},"up",idx,0);
                check_cctv({i,j},"down",idx,0);
                check_cctv({i,j},"left",idx,0);
                check_cctv({i,j},"right",idx,0);
                idx++;
            }
        }
    }

    // permutation

}