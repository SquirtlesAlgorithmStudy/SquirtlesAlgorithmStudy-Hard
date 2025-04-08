#include <iostream>

using namespace std;
int N, M;
int grid[50][50];
int visited[50][50] = {0,};
int cnt = 0;
struct INFO{
    int r, c, dir;
};
INFO robot;
int dr[4] = {-1, 0, 1, 0}; // 북동남서
int dc[4] = {0, 1 ,0, -1};

int main(){
    cin >> N >> M;

    cin >> robot.r >> robot.c >> robot.dir;
    visited[robot.r][robot.c] = 1;
    cnt++;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
        }
    }
    
    while(1){
        bool needToClean = 0;

        // 상하좌우 탐색
        for(int i=0; i<4; i++){
            int nr = robot.r + dr[i];
            int nc = robot.c + dc[i];

            if(grid[nr][nc] == 0 && visited[nr][nc] == 0) needToClean = 1;
        }

        // 청소할 칸이 있다면,
        if(needToClean){
            while(1){
                // 일단 돌아
                robot.dir = (robot.dir+3)%4;

                // 그 방향으로 전진 시 청소가능구역 나오는지 확인
                int nr = robot.r + dr[robot.dir];
                int nc = robot.c + dc[robot.dir];
                if(grid[nr][nc] == 0 && visited[nr][nc] == 0){
                    robot.r = nr;
                    robot.c = nc;
                    visited[nr][nc] = 1;
                    cnt++;
                    break;
                }
            }            
        }
        // 없다면, 후진 가능여부 파악
        else{
            int backr = robot.r + dr[(robot.dir+2)%4];
            int backc = robot.c + dc[(robot.dir+2)%4];
            if(grid[backr][backc] == 1) break; // 후진 불가능 시 종료
            else{
                robot.r = backr;
                robot.c = backc;
            }
        }       
    }

    cout << cnt << endl;
}