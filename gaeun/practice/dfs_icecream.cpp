#include <iostream>
using namespace std;

int ice_tray[1000][1000];
int result = 0;
int N, M;

bool dfs(int row, int col){
    // 종료 조건
    if(row < 0 || col < 0 || row >= N || col >= M) return false; 
    if(ice_tray[row][col]) return false;

    else{
        // 방문처리
        ice_tray[row][col] = 1;

        // 상하좌우 인접노드 확인
        dfs(row-1, col);
        dfs(row+1, col);
        dfs(row, col-1);
        dfs(row, col+1);

        return true;
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> ice_tray[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(dfs(i,j)) result++;
        }
    }

    cout << result;
}