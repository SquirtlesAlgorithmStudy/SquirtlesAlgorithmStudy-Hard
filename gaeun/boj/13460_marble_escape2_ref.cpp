#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
char grid[10][10];

struct INFO{
    int rr, rc, br, bc;
    int cnt;
};

queue<INFO> q;
int visited[10][10][10][10] = {0,};

int bfs(){
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()){
        INFO curr;
        curr = q.front();
        q.pop();
        

        // 종료조건: cnt가 10을 넘어서거나, 빨간공만 출구에 도달하거나
        if(curr.cnt > 10) break;
        if(grid[curr.rr][curr.rc] == 'O' && grid[curr.br][curr.bc] != 'O') return curr.cnt;

        // 그 외엔 탐색 필요
        for(int i=0; i<4; i++){
            int nrr = curr.rr;
            int nrc = curr.rc;
            int nbr = curr.br;
            int nbc = curr.bc;

            // 빨간공 움직이기
            while(1){
                // 벽이나 출구가 아니라면, 움직이기 가능.
                if(grid[nrr][nrc] != '#' && grid[nrr][nrc] != 'O'){
                    nrr += dr[i];
                    nrc += dc[i];
                }
                else{
                    if(grid[nrr][nrc] == '#'){
                        nrr -= dr[i];
                        nrc -= dc[i];
                    }
                    break;
                }                
            }

            // 파란공 움직이기
            while(1){
                // 벽이나 출구가 아니라면, 움직이기 가능.
                if(grid[nbr][nbc] != '#' && grid[nbr][nbc] != 'O'){
                    nbr += dr[i];
                    nbc += dc[i];
                }
                else{
                    if(grid[nbr][nbc] == '#'){
                        nbr -= dr[i];
                        nbc -= dc[i];
                    }
                    break;
                }                
            }

            // 파란공과 빨간공이 한 열 or 한 행에서 같이 움직였다면, 조정 필요(더 멀리 있던 애가 한 칸 뒤로)
            if(nrr == nbr && nrc == nbc){
                int distR = abs(nrr - curr.rr) + abs(nrc - curr.rc);
                int distB = abs(nbr - curr.br) + abs(nbc - curr.bc);

                if(distR > distB){
                    nrr -= dr[i];
                    nrc -= dc[i];
                } 
                else{
                    nbr -= dr[i];
                    nbc -= dc[i];
                }
            }

            // 이미 진행했던 경우의 수인지 확인
            if(!visited[nrr][nrc][nbr][nbc]){
                visited[nrr][nrc][nbr][nbc] = 1;

                INFO next;
                next.rr = nrr;
                next.rc = nrc;
                next.br = nbr;
                next.bc = nbc;
                next.cnt = curr.cnt + 1;

                q.push(next);
            }
        }
    }
    return -1;
}

int main(){
    INFO start;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){
                start.rr = i;
                start.rc = j;
            }
            if(grid[i][j] == 'B'){
                start.br = i;
                start.bc = j;
            }
        }
    }
    start.cnt = 0;
    q.push(start);
    visited[start.rr][start.rc][start.br][start.bc] = 1;

    int ret = bfs();
    cout << ret << endl;
}