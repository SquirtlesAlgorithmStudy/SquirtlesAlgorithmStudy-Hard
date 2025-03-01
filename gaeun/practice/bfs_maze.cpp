#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int maze[200][200];
bool visited[200][200]={0,};
int dRow[4] = {-1, 1, 0, 0};
int dCol[4] = {0, 0, -1, 1};

int bfs(int row, int col){
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        visited[current.first][current.second] = 1;

        for(int i=0; i<4; i++){
            // 범위 내에 있고
            if(current.first+dRow[i]<0 || current.first+dRow[i]>=N || current.second+dCol[i]<0 || current.second+dCol[i]>=M) continue;

            // 괴물이 없는 부분이면서 방문 x 노드라면 q에 삽입
            if(maze[current.first+dRow[i]][current.second+dCol[i]] && !visited[current.first+dRow[i]][current.second+dCol[i]]){
                q.push({current.first+dRow[i], current.second+dCol[i]});
                maze[current.first+dRow[i]][current.second+dCol[i]] += maze[current.first][current.second];
                visited[current.first+dRow[i]][current.second+dCol[i]] = 1;
            }
        }
    }
    return maze[N-1][M-1];
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maze[i][j];
        }
    }

    cout << bfs(0,0) << endl;
}