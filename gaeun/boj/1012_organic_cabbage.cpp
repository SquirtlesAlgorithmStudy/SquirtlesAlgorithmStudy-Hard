#include <iostream>
#include <queue>

using namespace std;

int map[51][51] = {0,};
int visited[51][51] = {0, };
int dr[4] = {-1, 1, 0, 0}; // 상하좌우
int dc[4] = {0, 0, -1, 1};
int T, M, N, K;

void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(visited[nr][nc]) continue;
            if(map[nr][nc] == 0) continue;

            q.push({nr, nc});
            visited[nr][nc] = 1;
        }
    }
}

int main(){    
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    vector<int> answerVec;
    for(int i=0; i<T; i++){
        cin >> M >> N >> K;

        int ans = 0;
        queue<pair<int, int>> cabbageQ;
        for(int i=0; i<51; i++){
            for(int j=0; j<51; j++){
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for(int i=0; i<K; i++){
            int X, Y;
            cin >> X >> Y;
            map[Y][X] = 1;
            cabbageQ.push({Y, X});
        }

        while(!cabbageQ.empty()){
            pair<int, int> cabbageNode = cabbageQ.front();
            cabbageQ.pop();

            if(!visited[cabbageNode.first][cabbageNode.second]){
                bfs(cabbageNode.first, cabbageNode.second);
                ans++;
            }
        }

        answerVec.push_back(ans);
    }
    
    for(int i=0; i<answerVec.size(); i++){
        cout << answerVec[i] << endl;
    }
}

