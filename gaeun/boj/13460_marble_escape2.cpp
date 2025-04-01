#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
char grid[11][11];
int visitedR[11][11]={0,};
int visitedB[11][11]={0,};
queue<pair<int,int>> qR;
queue<pair<int,int>> qB;
bool flagR, flagB;
int level = 0;
pair<int,int> currR, currB;

// marble: marble to move, marble2: the other marble to detect collision, colour: the colour of marble to move
void moveMarble(pair<int, int> marble, pair<int, int> marble2, char colour, int dr, int dc){
    int nr = marble.first + dr;
    int nc = marble.second + dc;

    // 해당 방향으로 움직일 수 없음
    if(grid[nr][nc] == '#' || (nr == marble2.first && nc == marble2.second)) return;
    if(colour == 'R' && visitedR[nr][nc] == 1) return;
    if(colour == 'B' && visitedB[nr][nc] == 1) return;

    // 공 멈출때까지 움직여
    while(grid[nr][nc] == '.' && (nr != marble2.first || nc != marble2.second)){
        if(colour == 'R') visitedR[nr][nc] = 1;
        else visitedB[nr][nc] = 1;
        nr += dr;
        nc += dc;
    }

    // 움직인 후 벽 또는 다른 공을 마주했다면 
    if(grid[nr][nc] == '#' || (nr == marble2.first && nc == marble2.second)){
        nr -= dr;
        nc -= dc;
        if(colour == 'R'){
            qR.push({nr, nc});
            currR = {nr, nc};
        } 
        else{
            qB.push({nr, nc});
            currB = {nr, nc};
        } 
    }

    // 움직인 후 출구를 마주했다면
    else if(grid[nr][nc] == 'O'){
        if(colour == 'R'){
            flagR = 1;
            currR = {-1, -1}; // 출구로 빠져나갔음
        } 
        else{
            flagB = 1;
            currB = {-1, -1}; // 출구로 빠져나갔음
        } 
    }
}

int bfs(){
    while(!qR.empty()){
        int qSize = qR.size();
        level++;
        
        for(int i=0; i<qSize; i++){
            if(qB.empty()){
                // 상
                currR = qR.front();
                moveMarble(currR, currB, 'R', -1, 0);
                if(flagR) return level;
                else flagR = 0;

                // 하
                currR = qR.front();
                moveMarble(currR, currB, 'R', 1, 0);
                if(flagR) return level;
                else flagR = 0;

                // 좌
                currR = qR.front();
                moveMarble(currR, currB, 'R', 0, -1);
                if(flagR) return level;
                else flagR = 0;

                // 우
                currR = qR.front();
                moveMarble(currR, currB, 'R', 0, 1);
                if(flagR) return level;
                else flagR = 0;

                qR.pop();
            }
            else{                
                //상
                currR = qR.front(); currB = qB.front();
                if(currR.first < currB.first){
                    moveMarble(currR, currB, 'R', -1, 0);
                    moveMarble(currB, currR, 'B', -1, 0);
                }
                else{
                    moveMarble(currB, currR, 'B', -1, 0);
                    if(flagB == 0) moveMarble(currR, currB, 'R', -1, 0);
                }
                if(flagR == 1 && flagB == 0) return level;
                else {flagR = 0; flagB = 0;}

                //하
                currR = qR.front(); currB = qB.front();
                if(currR.first > currB.first){
                    moveMarble(currR, currB, 'R', 1, 0);
                    moveMarble(currB, currR, 'B', 1, 0);
                }
                else{
                    moveMarble(currB, currR, 'B', 1, 0);
                    if(flagB == 0) moveMarble(currR, currB, 'R', 1, 0);
                }
                if(flagR == 1 && flagB == 0) return level;
                else {flagR = 0; flagB = 0;}

                //좌
                currR = qR.front(); currB = qB.front();
                if(currR.second < currB.second){
                    moveMarble(currR, currB, 'R', 0, -1);
                    moveMarble(currB, currR, 'B', 0, -1);
                }
                else{
                    moveMarble(currB, currR, 'B', 0, -1);
                    if(flagB == 0) moveMarble(currR, currB, 'R', 0, -1);
                }
                if(flagR == 1 && flagB == 0) return level;
                else {flagR = 0; flagB = 0;}

                //우
                currR = qR.front(); currB = qB.front();
                if(currR.second < currB.second){
                    moveMarble(currR, currB, 'R', 0, 1);
                    moveMarble(currB, currR, 'B', 0, 1);
                }
                else{
                    moveMarble(currB, currR, 'B', 0, 1);
                    if(flagB == 0) moveMarble(currR, currB, 'R', 0, 1);
                }
                if(flagR == 1 && flagB == 0) return level;
                else {flagR = 0; flagB = 0;}

                qR.pop(); qB.pop();
            }
            // cout << "level " << level << " is done, current queue: " << endl;
            // queue<pair<int,int>> tmp;
            // tmp = qR;
            // cout << "qR: ";
            // while(!tmp.empty()){
            //     cout << "(" << tmp.front().first <<"," << tmp.front().second << ")," << " ";
            //     tmp.pop();
            // }
            // cout << endl;
            // tmp = qB;
            // cout << "qB: ";
            // while(!tmp.empty()){
            //     cout << "(" << tmp.front().first <<"," << tmp.front().second << ")," << " ";
            //     tmp.pop();
            // }
            // cout << endl;
        }

        if(level >= 10) return -1;
    }
    return -1;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){
                currR = {i,j};
                qR.push({i,j});
                grid[i][j] = '.';
                visitedR[i][j] = 1;
            }
            if(grid[i][j] == 'B'){
                currB = {i,j};
                qB.push({i,j});
                grid[i][j] = '.';
                visitedB[i][j] = 1;
            }
        }
    }
    

    cout << bfs() << endl;
}

// int main(){
//     N = 7;
//     M = 7;
//     vector<string> input = {
//         "#######",
//         "#...RB#",
//         "#.#####",
//         "#.....#",
//         "#####.#",
//         "#O....#",
//         "#######"
//     };

//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < M; j++) {
//             grid[i][j] = input[i][j];

//             if(grid[i][j] == 'R') {
//                 currR = {i, j};
//                 qR.push({i, j});
//                 grid[i][j] = '.';
//             }
//             if(grid[i][j] == 'B') {
//                 currB = {i, j};
//                 qB.push({i, j});
//                 grid[i][j] = '.';
//             }
//         }
//     }

//     cout << bfs() << endl;
// }