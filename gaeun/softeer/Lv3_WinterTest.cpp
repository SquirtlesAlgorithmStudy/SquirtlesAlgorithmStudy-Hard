#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, M;
int grid[100][100];
int visited[100][100]={0,};
int contact[100][100]={0,};
int dRow[4] = {-1, 1, 0, 0};
int dCol[4] = {0, 0, -1, 1};
int result = 0;

void dfs(int row, int col){
    // check range
    if(row<0 || col<0 || row>=N || col >=M) return;

    // check visit
    if(visited[row][col]) return;
    
    if(grid[row][col] == 0){
        // make a visit
        visited[row][col] = 1;

        // search 상하좌우
        for(int i=0; i<4; i++){
            // range check
            if(row+dRow[i]<0 || col+dCol[i]<0 || row+dRow[i]>=N || col+dCol[i]>=N) continue;

            if(grid[row+dRow[i]][col+dCol[i]] == 1) contact[row+dRow[i]][col+dCol[i]]++;
            dfs(row+dRow[i], col+dCol[i]);            
        }
    }
}

void updategrid(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(contact[i][j] >= 2){
                grid[i][j] = 0;  
            }
        }
    }
}

bool checkAllZero(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j]){
                return 0;   
            }
        }
    }
    return 1;
}

void clearVisitedAndContact(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j] = 0;
            contact[i][j] = 0;
        }
    }
}

int main(int argc, char** argv)
{
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
        }
    }

    bool isAllZero = checkAllZero();

    while(!isAllZero){
        // 얼음이 남아있다면 do dfs
        dfs(0,0);

        // 접촉 횟수에 따라 변화된 grid 업데이트
        updategrid();

        // dfs 한 번 끝나면 시간 증가
        result++;

        // 방문 기록 및 접촉 기록 초기화
        clearVisitedAndContact();

        // 모든 얼음이 녹았는지 확인
        isAllZero = checkAllZero();
    }

    cout << result << endl;
    
   return 0;
}