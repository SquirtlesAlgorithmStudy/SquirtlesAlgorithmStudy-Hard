#include <iostream>

using namespace std;

int N, L;
int grid[100][100];
int cnt = 0;

int main(){
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
        }
    }

    // 세로 길 탐색
    int c, r;
    for(c=0; c<N; c++){
        bool isValid = 1;
        bool isRamp[100][100] = {0,};
        int accum = 1;
        for(r=0; r<N-1; r++){
            // 1. 단차 없음
            if(grid[r+1][c] - grid[r][c] == 0){
                accum++;
            }

            // 2. 올라가는 경사
            else if(grid[r+1][c] - grid[r][c] == 1){
                // 경사를 놓을 수 있는 충분한 공간이 나왔었는지 확인
                if(accum < L){
                    isValid = false;
                    accum = 1;
                    break;
                }

                // 그 공간들에 이미 경사로가 놓여있는건 아닌지 확인
                else{
                    for(int i=0; i<L; i++){
                        if(isRamp[r-i][c]){
                            isValid = false;
                            break;
                        }
                    }
                    accum = 1;
                }
                if(!isValid) break;

                else{
                    // 경사로 놓았다고 표시 - maybe redundant? 
                    for(int i=0; i<L; i++){
                        isRamp[r-i][c] = true;
                    }
                }
            }
            
            // 3. 내려가는 경사
            else if(grid[r+1][c] - grid[r][c] == -1){
                // 이미 경사로가 놓여있는것은 아닌지 체크
                for(int i=1; i<=L; i++){
                    if(r+i >= N){
                        isValid = false;
                        break;
                    }
                    if(isRamp[r+i][c]){
                        isValid = false;
                        break;
                    }
                }
                accum = 1;
                if(!isValid) break;

                // 경사로 놓을 수 있는지 체크
                else{
                    for(int i=1; i<L; i++){
                        // L개의 같은 층이 나오지 않는다면 경사로 놓을 수 x. 
                        if(r+1+i >= N){
                            isValid = false;
                            break;
                        }
                        if(grid[r+1+i][c] != grid[r+1][c]){
                            isValid = false;
                            break;
                        }
                    }
                    accum = 1;
                    if(!isValid) break;

                    // 경사로 놓았다고 표시
                    else{
                        for(int i=1; i<=L; i++){
                            isRamp[r+i][c] = true;
                        }
                    }
                }
            }
            // 4. 2층 이상의 단차: 길 x
            else{
                accum = 1;
                isValid = false;
                break;
            }

        }
        if(isValid){
            // cout << "valid vertical line: c=" << c << endl;
            cnt++;
        } 
    }

    // 가로 길 탐색
    for(r=0; r<N; r++){
        bool isValid = 1;
        bool isRamp[100][100] = {0,};
        int accum = 1;
        for(c=0; c<N-1; c++){
            // 1. 단차 없음
            if(grid[r][c+1] - grid[r][c] == 0){
                accum++;
            }

            // 2. 올라가는 경사
            else if(grid[r][c+1] - grid[r][c] == 1){
                // 경사를 놓을 수 있는 충분한 공간이 나왔었는지 확인
                if(accum < L){
                    isValid = false;
                    accum = 1;
                    break;
                }

                // 그 공간들에 이미 경사로가 놓여있는건 아닌지 확인
                else{
                    for(int i=0; i<L; i++){
                        if(isRamp[r][c-i]){
                            isValid = false;
                            break;
                        }
                    }
                    accum = 1;
                }
                if(!isValid) break;

                else{
                    // 경사로 놓았다고 표시 - maybe redundant? 
                    for(int i=0; i<L; i++){
                        isRamp[r][c-i] = true;
                    }
                }
            }
            
            // 3. 내려가는 경사
            else if(grid[r][c+1] - grid[r][c] == -1){
                // 이미 경사로가 놓여있는것은 아닌지 체크
                for(int i=1; i<=L; i++){
                    if(c+i >= N){
                        isValid = false;
                        break;
                    }
                    if(isRamp[r][c+i]){
                        isValid = false;
                        break;
                    }
                }
                accum = 1;
                if(!isValid) break;

                // 경사로 놓을 수 있는지 체크
                else{
                    for(int i=1; i<L; i++){
                        // L개의 같은 층이 나오지 않는다면 경사로 놓을 수 x. 
                        if(c+1+i >= N){
                            isValid = false;
                            break;
                        }
                        if(grid[r][c+1+i] != grid[r][c+1]){
                            isValid = false;
                            break;
                        }
                    }
                    accum = 1;
                    if(!isValid) break;

                    // 경사로 놓았다고 표시
                    else{
                        for(int i=1; i<=L; i++){
                            isRamp[r][c+i] = true;
                        }
                    }
                }
            }
            // 4. 2층 이상의 단차: 길 x
            else{
                accum = 1;
                isValid = false;
                break;
            }

        }
        if(isValid){
            // cout << "valid horizontal line: r=" << r << endl;
            cnt++;
        } 
    }

    cout << cnt << endl;
}