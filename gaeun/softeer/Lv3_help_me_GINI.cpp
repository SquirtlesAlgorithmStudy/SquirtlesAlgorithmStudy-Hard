#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char grid[51][51];
int visited_taebum[51][51]; // -1로 초기화(거리 누적)
int visited_sonagi[51][51] = {0, };
int dr[4] = {-1, 1, 0, 0}; // 상하좌우
int dc[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
pair<int, int> home;
pair<int, int> tail;

void update_sonagi(){
    // clear visited_sonagi
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            visited_sonagi[i][j] = 0;
        }
    }

    // spread rain
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(grid[i][j] == '*' && visited_sonagi[i][j] != 1){
                visited_sonagi[i][j] = 1;
                for(int k=0; k<4; k++){
                    int nr = i+dr[k];
                    int nc = j+dc[k];

                    if(nr < 0 || nr >= R || nc <0 || nc >= C) continue;
                    if(visited_sonagi[nr][nc] == 1) continue;

                    if(grid[nr][nc] == '.'){
                        grid[nr][nc] = '*';
                        visited_sonagi[nr][nc] = 1;
                    } 
                }
            }
        }
    }
}

// tail로 각 level 유지
// int move_taebum(){
//     while(!q.empty()){
//         pair<int, int> curr = q.front();
//         q.pop();

//         if(curr == home) return visited_taebum[curr.first][curr.second];

//         for(int i=0; i<4; i++){
//             int nr = curr.first + dr[i];
//             int nc = curr.second + dc[i];

//             if(nr < 0 || nr >= R || nc <0 || nc >= C) continue;
//             if(grid[nr][nc]=='X' || grid[nr][nc]=='*') continue;
//             if(visited_taebum[nr][nc] > -1) continue;

//             q.push({nr, nc});
//             visited_taebum[nr][nc] = visited_taebum[curr.first][curr.second] + 1;
//         }

//         if(curr == tail){
//             update_sonagi();
//             tail = q.back();
//         } 
//     }
//     return -1;
// }

// 노드 개수를 기록해서 level 유지
int move_taebum(){
    while(!q.empty()){
        int qSize = q.size();
        for(int i=0; i<qSize; i++){
            pair<int, int> curr = q.front();
            q.pop();

            if(curr == home) return visited_taebum[curr.first][curr.second];

            for(int i=0; i<4; i++){
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];

                if(nr < 0 || nr >= R || nc <0 || nc >= C) continue;
                if(grid[nr][nc]=='X' || grid[nr][nc]=='*') continue;
                if(visited_taebum[nr][nc] > -1) continue;

                q.push({nr, nc});
                visited_taebum[nr][nc] = visited_taebum[curr.first][curr.second] + 1;
            }
        }
        update_sonagi();
    }
    return -1;
}

int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            visited_taebum[i][j] = -1;
        }        
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char c;
            cin >> c;
            grid[i][j] = c;
            if(c == 'W'){
                q.push({i, j});
                visited_taebum[i][j] = 0;
            }
            if(c == 'H'){
                home = {i,j};
            }
        }
    }

    tail = q.back();
    update_sonagi();        

    int result = move_taebum();
    if(result == -1) cout << "FAIL" << endl;
    else cout << result << endl;
}