#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N,K;
int grid[13][13];
struct horseINFO{
    int r, c, dir;
};
vector<horseINFO> horse;
stack<int> s[13][13];
int turn = 0;
bool isFour = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }
    }
    horse.resize(K+1);
    for(int i=1; i<=K; i++){
        horseINFO h;
        cin >> h.r >> h.c >> h.dir;
        horse[i] = h;
        s[h.r][h.c].push(i);
    }
    // cout << "\n[init]\n";
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         if (!s[i][j].empty()) {
    //             stack<int> tmp = s[i][j]; // 복사본 사용
    //             vector<int> horses;
    //             while (!tmp.empty()) {
    //                 horses.push_back(tmp.top());
    //                 tmp.pop();
    //             }
    //             reverse(horses.begin(), horses.end()); // bottom → top 순서대로 출력

    //             cout << "s[" << i << "][" << j << "] = ";
    //             for (int h : horses) cout << h << " ";
    //             cout << "\n";
    //         }
    //     }
    // }

    while(1){
        turn++;

        if(turn >= 1000){
            break;
        }

        // move horses
        for(int i=1; i<=K; i++){
            horseINFO curr = horse[i];
            deque<int> dq;
            int dr[5] = {0, 0, 0, -1, 1}; // 우, 좌, 상, 하, idx 0 안씀
            int dc[5] = {0, 1, -1, 0, 0}; 

            // cout << "move " << i << "\n";
            // stack<int> tmp = s[curr.r][curr.c];
            // cout << "stack[" << curr.r << "][" << curr.c <<"]: ";
            // while(!tmp.empty()){
            //     cout << tmp.top();
            //     tmp.pop();
            // }
            // cout << "\n";

            // 다음 칸이 범위를 벗어났거나, 파랑이라면 방향 전환
            int nr = curr.r + dr[curr.dir], nc = curr.c + dc[curr.dir];
            if(nr<1 || nr>N || nc<1 || nc>N || grid[nr][nc] == 2){
                if(curr.dir == 1 || curr.dir == 3) horse[i].dir += 1;
                if(curr.dir == 2 || curr.dir == 4) horse[i].dir -= 1;
                nr = curr.r + dr[horse[i].dir]; nc = curr.c + dc[horse[i].dir];
            }

            // 이동 불가능
            if(nr<1 || nr>N || nc<1 || nc>N || grid[nr][nc] == 2) continue;

            // 이동 가능
            while(1){
                int horseNum = s[curr.r][curr.c].top();
                horse[horseNum].r = nr; horse[horseNum].c = nc;
                dq.push_back(horseNum);
                s[curr.r][curr.c].pop();
                if(horseNum == i) break;
            }

            if(grid[nr][nc] == 0){ // 흰색
                while(!dq.empty()){
                    s[nr][nc].push(dq.back());
                    dq.pop_back();
                }
            }

            if(grid[nr][nc] == 1){ // 빨강
                while(!dq.empty()){
                    s[nr][nc].push(dq.front());
                    dq.pop_front();
                }
            }

            // after moving each horse, check the existance of 4 horse stack
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(s[i][j].size() >= 4){
                        isFour = true;
                        break;
                    } 
                }
                if(isFour) break;
            }
            if(isFour) break;

            // cout << "after move: \n";
            // tmp = s[curr.r][curr.c];
            // cout << "stack[" << curr.r << "][" << curr.c <<"]: ";
            // while(!tmp.empty()){
            //     cout << tmp.top();
            //     tmp.pop();
            // }
            // cout << "\n";
            // tmp = s[nr][nc];
            // cout << "stack[" << nr << "][" << nc <<"]: ";
            // while(!tmp.empty()){
            //     cout << tmp.top();
            //     tmp.pop();
            // }
            // cout << "\n";
        }
        if(isFour) break;
    }

    if(turn >= 1000) cout << -1 << "\n";
    else cout << turn << "\n";
}