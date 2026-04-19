#include <iostream>
#include <queue>
#include <cstring> // memset

using namespace std;

int map[101][101] = {0,};
int visited[101][101] = {0, };
int N, M;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool isCheeseRemained(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 1) return true;
        }
    }
    return false;
}

void findOutsideAirBfs(int r, int c){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = 1;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(visited[nr][nc]) continue;
            if(map[nr][nc] == 1) continue;

            q.push({nr, nc});
            visited[nr][nc] = 1;
        }
    }
}

void removeCheese(){
    queue<pair<int, int>> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 1){
                int cnt = 0;
                for(int k=0; k<4; k++){
                    if(visited[i+dr[k]][j+dc[k]] == 1) cnt++;
                }
                if(cnt >= 2) q.push({i,j});
            }            
        }
    }

    while(!q.empty()){
        pair<int, int> remove = q.front();
        q.pop();
        map[remove.first][remove.second] = 0;
        visited[remove.first][remove.second] = 1;
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    int ans = 0;
    while(isCheeseRemained()){
        findOutsideAirBfs(0,0);
        removeCheese();
        ans++;
    }

    cout << ans << endl;
}