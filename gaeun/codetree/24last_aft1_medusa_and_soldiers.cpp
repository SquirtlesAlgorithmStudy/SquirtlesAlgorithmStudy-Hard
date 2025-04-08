#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
pair<int, int> home, park;
pair<int, int> medusa;
int grid[50][50];
vector<vector<int>> soldier(50,vector<int>(50, 0));
vector<pair<int, int>> path;
int visited[50][50] = {0, };
int cntUP=0, cntDOWN=0, cntLEFT=0, cntRIGHT=0;
int dr[4] = {-1, 1, 0, 0}; // 상하좌우
int dc[4] = {0, 0, -1, 1};
vector<vector<int>> sight(50,vector<int>(50, 0));
int stoneCnt=0, moveCnt=0, attackCnt=0;

bool moveMedusa(int r, int c);
vector<vector<int>> seeUP();
vector<vector<int>> seeDOWN();
vector<vector<int>> seeLEFT();
vector<vector<int>> seeRIGHT();
void moveSoldierAndAttack();

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    cin >> home.first >> home.second >> park.first >> park.second;
    medusa.first = home.first;
    medusa.second = home.second;
    
    for(int i=0; i<M; i++){
        int r, c;
        cin >> r >> c;
        soldier[r][c]++;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
        }
    }

    // creat medusa's route first
    bool isRoute = moveMedusa(home.first, home.second);
    if(isRoute == 0) cout << -1 << "\n";
    else{
        for(int i=1; i<path.size()-1; i++){
            pair<int, int> p = path[i]; // 0(home 위치)이랑 마지막 인덱스(park)는 빼고
            // move medusa
            medusa.first = p.first; medusa.second = p.second;
            if(soldier[medusa.first][medusa.second] > 0) soldier[medusa.first][medusa.second] = 0;
            
            // medusa's attack
            seeUP(); seeDOWN(); seeLEFT(); seeRIGHT();
            int max = cntUP; string dir = "UP";
            if(max < cntDOWN){max = cntDOWN; dir = "DOWN";}
            if(max < cntLEFT){max = cntLEFT; dir = "LEFT";}
            if(max < cntRIGHT){max = cntRIGHT; dir = "RIGHT";}
            // if(dir == "UP"){ sight = seeUP(); stoneCnt = cntUP; }
            // else if(dir == "DOWN"){ sight = seeDOWN(); stoneCnt = cntDOWN; }
            // else if(dir == "LEFT"){ sight = seeLEFT(); stoneCnt = cntLEFT; }
            // else if(dir == "RIGHT"){ sight = seeRIGHT(); stoneCnt = cntRIGHT; }

            // soldier's move and attack
            moveSoldierAndAttack();      

            // print the result
            cout << moveCnt << " " << stoneCnt << " " << attackCnt << "\n";
        }
        cout << 0 << "\n";
    }    
}

bool moveMedusa(int r, int c){
    queue<pair<int, int>> q;
    pair<int, int> parent[50][50];
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
        parent[i][j] = {-1, -1};

    q.push({r, c});
    visited[r][c] = 1;

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();

        if(curr.first == park.first && curr.second == park.second) break;

        for(int i=0; i<4; i++){
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
            if(visited[nr][nc]) continue;
            if(grid[nr][nc] == 1) continue;

            q.push({nr,nc});
            visited[nr][nc] = 1;
            parent[nr][nc] = {curr.first, curr.second};
        }
    }

    if(visited[park.first][park.second] == 0) return false;

    pair<int, int> node = park;
    while(node != home){
        path.push_back(node);
        node = parent[node.first][node.second];
    }
    path.push_back(home);
    reverse(path.begin(), path.end());
    return true;
}

vector<vector<int>> seeUP(){
    cntUP = 0;
    int dist = 1;
    queue<pair<int,int>> q;
    vector<vector<int>> sight(50, vector<int>(50, 0));

    // fill medusa's sight first
    while(medusa.first-dist >= 0){
        int l, r;
        if(medusa.second-dist >= 0) l = medusa.second-dist;
        else l=0;
        if(medusa.second+dist < N) r = medusa.second+dist;
        else r=N-1;

        for(int j=l; j<=r; j++){
            if(soldier[medusa.first-dist][j] > 0){
                q.push({medusa.first-dist, j});
                cntUP += soldier[medusa.first-dist][j];
            }
            sight[medusa.first-dist][j] = 1;
        }
        dist++;
    } 
    queue<pair<int,int>> tmp = q;

    // behind soldier
    while(!q.empty()){
        pair<int, int> sol = q.front();
        q.pop();
        if(sol.second < medusa.second){
            int d = 1;
            int l, r;
            while(sol.first - d >= 0){
                if(sol.second - d >= 0) l = sol.second - d;
                else l = 0;
                r = sol.second;

                for(int j=l; j<=r; j++){
                    sight[sol.first - d][j] = 0;
                }
                d++;
            }
        }
        else if(sol.second == medusa.second){
            int d=1;
            while(sol.first - d >= 0){
                sight[sol.first-d][medusa.second] = 0;
                d++;
            }
        }
        else if(sol.second > medusa.second){
            int d = 1;
            int l, r;
            while(sol.first - d >= 0){
                if(sol.second + d >= 0) r = sol.second + d;
                else r = N-1;
                l = sol.second;

                for(int j=l; j<=r; j++){
                    sight[sol.first - d][j] = 0;
                }
                d++;
            }
        }
    }

    // cout << "\n";
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout << sight[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while(!tmp.empty()){
        pair<int,int> s = tmp.front();
        tmp.pop();
        if(sight[s.first][s.second] == 0) cntUP -= soldier[s.first][s.second];
    }
    return sight;
}

vector<vector<int>> seeDOWN(){
    cntDOWN = 0;
    int dist = 1;
    queue<pair<int,int>> q;
    vector<vector<int>> sight(50, vector<int>(50, 0));

    // fill medusa's sight first
    while(medusa.first+dist < N){
        int l, r;
        if(medusa.second-dist >= 0) l = medusa.second-dist;
        else l=0;
        if(medusa.second+dist < N) r = medusa.second+dist;
        else r=N-1;

        for(int j=l; j<=r; j++){
            if(soldier[medusa.first+dist][j] > 0){
                q.push({medusa.first+dist, j});
                cntDOWN += soldier[medusa.first+dist][j];
            }
            sight[medusa.first+dist][j] = 1;
        }
        dist++;
    } 
    queue<pair<int,int>> tmp = q;

    // behind soldier
    while(!q.empty()){
        pair<int, int> sol = q.front();
        q.pop();
        if(sol.second < medusa.second){
            int d = 1;
            int l, r;
            while(sol.first + d < N){
                if(sol.second - d >= 0) l = sol.second - d;
                else l = 0;
                r = sol.second;

                for(int j=l; j<=r; j++){
                    sight[sol.first + d][j] = 0;
                }
                d++;
            }
        }
        else if(sol.second == medusa.second){
            int d=1;
            while(sol.first + d < N){
                sight[sol.first+d][medusa.second] = 0;
                d++;
            }
        }
        else if(sol.second > medusa.second){
            int d = 1;
            int l, r;
            while(sol.first + d < N){
                if(sol.second + d >= 0) r = sol.second + d;
                else r = N-1;
                l = sol.second;

                for(int j=l; j<=r; j++){
                    sight[sol.first + d][j] = 0;
                }
                d++;
            }
        }
    }

    while(!tmp.empty()){
        pair<int,int> s = tmp.front();
        tmp.pop();
        if(sight[s.first][s.second] == 0) cntDOWN -= soldier[s.first][s.second];
    }
    return sight;
}

vector<vector<int>> seeLEFT(){
    cntLEFT = 0;
    int dist = 1;
    queue<pair<int,int>> q;
    vector<vector<int>> sight(50, vector<int>(50, 0));

    // fill medusa's sight first
    while(medusa.second-dist >= 0){
        int u, d;
        if(medusa.first-dist >= 0) u = medusa.first-dist;
        else u=0;
        if(medusa.first+dist < N) d = medusa.first+dist;
        else d=N-1;

        for(int i=u; i<=d; i++){
            if(soldier[i][medusa.second-dist] > 0){
                q.push({i, medusa.second-dist});
                cntLEFT += soldier[i][medusa.second-dist];
            }
            sight[i][medusa.second-dist] = 1;
        }
        dist++;
    } 
    queue<pair<int,int>> tmp = q;

    // behind soldier
    while(!q.empty()){
        pair<int, int> sol = q.front();
        q.pop();
        if(sol.first < medusa.first){ // 위에 있는 병사들
            int d = 1;
            int u, l;
            while(sol.second - d >= 0){
                if(sol.first - d >= 0) u = sol.first - d;
                else u = 0;
                l = sol.first;

                for(int i=u; i<=l; i++){
                    sight[i][sol.second - d] = 0;
                }
                d++;
            }
        }
        else if(sol.first == medusa.first){
            int d=1;
            while(sol.second - d >= 0){
                sight[medusa.first][sol.second - d] = 0;
                d++;
            }
        }
        else if(sol.first > medusa.first){
            int d = 1;
            int u, l;
            while(sol.second - d >= 0){
                if(sol.first + d < N) l = sol.first + d;
                else l = N-1;
                u = sol.first;

                for(int i=u; i<=l; i++){
                    sight[i][sol.second - d] = 0;
                }
                d++;
            }
        }
    }

    while(!tmp.empty()){
        pair<int,int> s = tmp.front();
        tmp.pop();
        if(sight[s.first][s.second] == 0) cntLEFT -= soldier[s.first][s.second];
    }
    return sight;
}

vector<vector<int>> seeRIGHT(){
    cntRIGHT = 0;
    int dist = 1;
    queue<pair<int,int>> q;
    vector<vector<int>> sight(50, vector<int>(50, 0));

    // fill medusa's sight first
    while(medusa.second+dist < N){
        int u, d;
        if(medusa.first-dist >= 0) u = medusa.first-dist;
        else u=0;
        if(medusa.first+dist < N) d = medusa.first+dist;
        else d=N-1;

        for(int i=u; i<=d; i++){
            if(soldier[i][medusa.second+dist] > 0){
                q.push({i, medusa.second+dist});
                cntRIGHT += soldier[i][medusa.second+dist];
            }
            sight[i][medusa.second+dist] = 1;
        }
        dist++;
    } 
    queue<pair<int,int>> tmp = q;

    // behind soldier
    while(!q.empty()){
        pair<int, int> sol = q.front();
        q.pop();
        //cout << "soldier(" << sol.first << ", " << sol.second << "): ";
        if(sol.first < medusa.first){
            int d = 1;
            int u, l;
            while(sol.second + d < N){
                if(sol.first - d >= 0) u = sol.first - d;
                else u = 0;
                l = sol.first;

                for(int i=u; i<=l; i++){
                    //cout << "i: " << i << ", j: " << sol.second + d << "\n";
                    sight[i][sol.second + d] = 0;
                }
                d++;
            }
        }
        else if(sol.first == medusa.first){
            int d=1;
            while(sol.second + d < N){
                sight[medusa.first][sol.second + d] = 0;
                d++;
            }
        }
        else if(sol.first > medusa.first){
            int d = 1;
            int u, l;
            while(sol.second + d < N){
                if(sol.first + d < N) l = sol.first + d;
                else l = N-1;
                u = sol.first;

                for(int i=u; i<=l; i++){
                    sight[i][sol.second + d] = 0;
                }
                d++;
            }
        }
    }

    // cout << "\n";
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout << sight[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while(!tmp.empty()){
        pair<int,int> s = tmp.front();
        tmp.pop();
        if(sight[s.first][s.second] == 0) cntRIGHT -= soldier[s.first][s.second];
    }
    return sight;
}

void moveSoldierAndAttack(){
    moveCnt = 0; attackCnt = 0;
    vector<vector<int>> tmp = soldier;

    for(int move=0; move<2; move++){
        // cout << "move " << move << ": " << "\n";
        // cout << "current soldier: \n";
        // for(int r=0; r<N; r++){
        //     for(int c=0; c<N; c++){
        //         cout << soldier[r][c] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "current sight: \n";
        // for(int r=0; r<N; r++){
        //     for(int c=0; c<N; c++){
        //         cout << sight[r][c] << " ";
        //     }
        //     cout << "\n";
        // }
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(soldier[r][c] > 0 && sight[r][c] == 0){
                    for(int i=0; i<4; i++){
                        int idx;
                        if(move == 0) idx = i;
                        if(move == 1) idx = (i+2)%4; 

                        int nr = r + dr[idx]; int nc = c + dc[idx];
                        int dist1 = abs(r-medusa.first) + abs(c-medusa.second);
                        int dist2 = abs(nr-medusa.first) + abs(nc-medusa.second);

                        if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
                        if(dist1 <= dist2) continue;
                        if(sight[nr][nc]==1) continue;

                        // cout << "r, c: " << r << ", " << c << "\n";
                        // cout << "nr, nc: " << nr << ", " << nc << "\n"; 
                        moveCnt += soldier[r][c];
                        if(nr == medusa.first && nc == medusa.second){
                            attackCnt += soldier[r][c];
                            tmp[r][c] -= soldier[r][c];
                            break;
                        }
                        tmp[nr][nc] += soldier[r][c];
                        tmp[r][c] -= soldier[r][c];
                        break;
                    }
                }
            }
        }
        soldier = tmp;
    }
}