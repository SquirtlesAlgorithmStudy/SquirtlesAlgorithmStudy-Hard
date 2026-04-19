#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int map[9][9] = {0, };
int visited[9][9] = {0, };
int maxSafeArea = 0;
int debugging = 0;

int calcSafeArea(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void dfs(int r, int c){
    visited[r][c] = 1;

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
        if(visited[nr][nc]) continue;
        if(map[nr][nc] != 0) continue;

        map[nr][nc] = 2;
        dfs(nr, nc);
    }
}

void bfs(int r, int c){
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
            if(map[nr][nc] != 0) continue;

            map[nr][nc] = 2;
            visited[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
}

void spreadVirus(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 2 && visited[i][j] == 0) bfs(i, j);
        }
    }
}

void makeWall(int r, int c, int cnt){    
    if(cnt == 3){
        int mapAfterWall[9][9];
        memcpy(mapAfterWall, map, sizeof(map));

        spreadVirus();

        int tmp = calcSafeArea();
        maxSafeArea = max(maxSafeArea, tmp);

        memset(visited, 0, sizeof(visited));
        memcpy(map, mapAfterWall, sizeof(mapAfterWall));
        return;
    }

    for(int i=r; i<N; i++){
        int j = (i==r) ? c : 0;
        for(; j<M; j++){
            if(map[i][j] != 0) continue;
            map[i][j] = 1;
            makeWall(i, j+1, cnt+1);   
            map[i][j] = 0;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    makeWall(0,0,0);

    cout << maxSafeArea << endl;
}