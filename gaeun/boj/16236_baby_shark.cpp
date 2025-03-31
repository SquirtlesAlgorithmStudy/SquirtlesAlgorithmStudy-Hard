#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int grid[21][21];
int visited[21][21] = {0,};
int dr[4] = {-1, 0, 0, 1}; // 상,좌,우,하
int dc[4] = {0, -1, 1, 0};
pair<int, int> shark;
pair<int, int> tail;
int sharkSize = 2;
int eat = 0;
int time = 0;
int dist = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<pair<int, int>> minus_pq; // 위에 선언 기억 안나면 - 붙여서 넣어야지 뭐

bool no_more_fish(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]>0 && grid[i][j]<sharkSize) return false;
        }
    }
    return true;
}

void clear_visited(pair<int, int> exception){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j] = 0;
        }
    }
    visited[exception.first][exception.second] = 1;
}

void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = true;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
            if(grid[nr][nc] > sharkSize) continue;
            if(visited[nr][nc]) continue;
            // if(grid[nr][nc]>0 && grid[nr][nc]<sharkSize) pq.push({nr,nc});
            if(grid[nr][nc]>0 && grid[nr][nc]<sharkSize) minus_pq.push({-nr,-nc});

            q.push({nr, nc});
            visited[nr][nc] = true;
        }
        if(curr == tail){
            dist++; 
            tail = q.back();

            // eat from pq
            // if(!pq.empty()){
            //     pair<int, int> fish;
            //     fish = pq.top();
            //     while(!pq.empty()) pq.pop();
            if(!minus_pq.empty()){
                pair<int, int> fish;
                fish = minus_pq.top();
                fish.first = fish.first * -1;
                fish.second = fish.second * -1;
                while(!minus_pq.empty()) minus_pq.pop();

                time += dist;
                grid[shark.first][shark.second] = 0;
                grid[fish.first][fish.second] = 9;
                shark = fish;
                eat++;
                if(eat == sharkSize){
                    sharkSize++;
                    eat = 0;
                }

                // cout << "(" << fish.first << ", " << fish.second << ")" << "-> eat: " << eat << ", sharkSize: " << sharkSize << ", time: " << time << endl;

                if(no_more_fish()) return;

                while(!q.empty()) q.pop();
                q.push(fish);
                tail = fish;
                dist = 0;

                clear_visited(fish);
            }
        } 
    }
    
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 9){
                shark.first = i;
                shark.second = j;
                tail = shark;
            } 
        }
    }
    
    if(!no_more_fish()) bfs(shark.first, shark.second);

    cout << time << endl;
}