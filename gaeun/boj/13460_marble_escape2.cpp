#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
char grid[11][11];
struct INFO{
    int redR, redC, blueR, blueC, cnt;
};
queue<INFO> q;
bool visited[11][11][11][11] = {0, };
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int answer = INT_MAX;

bool bfs(){
    while(!q.empty()){
        INFO curr = q.front();
        q.pop();

        if(curr.cnt >= 10) return false;        

        for(int i=0; i<4; i++){
            int nrRed = curr.redR;
            int ncRed = curr.redC;
            int nrBlue = curr.blueR;
            int ncBlue = curr.blueC;

            // move red
            while(1){
                nrRed += dr[i]; ncRed += dc[i];
                if(grid[nrRed][ncRed] == '#' || grid[nrRed][ncRed] == 'O') break;
            }
            if(grid[nrRed][ncRed] == '#'){
                nrRed -= dr[i]; ncRed -= dc[i];
            }

            // move blue
            while(1){
                nrBlue += dr[i]; ncBlue += dc[i];
                if(grid[nrBlue][ncBlue] == '#' || grid[nrBlue][ncBlue] == 'O') break;
            }
            if(grid[nrBlue][ncBlue] == '#'){
                nrBlue -= dr[i]; ncBlue -= dc[i];
            }

            // adjust
            if(nrRed == nrBlue && ncRed == ncBlue && (grid[nrRed][ncRed] != 'O')){
                int distRed = abs(nrRed - curr.redR) + abs(ncRed - curr.redC);
                int distBlue = abs(nrBlue - curr.blueR) + abs(ncBlue - curr.blueC);

                if(distRed < distBlue){
                    nrBlue -= dr[i]; ncBlue -= dc[i];
                }
                else{
                    nrRed -= dr[i]; ncRed -= dc[i];
                }
            }

            // check conditions
            if(grid[nrBlue][ncBlue] == 'O') continue;
            if(visited[nrRed][ncRed][nrBlue][ncBlue]) continue;

            //cout << "nrRed, ncRed, nrBlue, ncBlue: " << nrRed << ", " << ncRed << ", " << nrBlue << ", " << ncBlue << "\n";
            if(grid[nrRed][ncRed] == 'O'){
                answer = curr.cnt + 1;
                return true;
            } 

            INFO next;
            next.redR = nrRed; next.redC = ncRed; next.blueR = nrBlue; next.blueC = ncBlue; next.cnt = curr.cnt+1;
            q.push(next);
            visited[nrRed][ncRed][nrBlue][ncBlue] = 1;
        }
    }
    return false;
}

int main(){
    cin >> N >> M;

    INFO init;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){
                init.redR = i;
                init.redC = j;
            }
            if(grid[i][j] == 'B'){
                init.blueR = i;
                init.blueC = j;
            }
        }
    }
    init.cnt = 0;
    q.push(init);
    visited[init.redR][init.redC][init.blueR][init.blueC] = 1;

    if(!bfs()) cout << -1 << "\n";
    else cout << answer << "\n";

}