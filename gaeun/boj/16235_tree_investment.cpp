#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int grid[11][11];
int A[11][11];
// vector<vector<vector<int>>> tree;
vector<int> tree[11][11];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            grid[i][j] = 5;
            cin >> A[i][j];
        }
    }

    //tree.resize(N+1,vector<vector<int>>(N+1));
    for(int i=0; i<M; i++){
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    int year = 0;
    while(year < K){
        // do sort first
        for(int r=1; r<=N; r++){
            for(int c=1; c<=N; c++){
                if(tree[r][c].size() > 0){
                    sort(tree[r][c].begin(), tree[r][c].end());
                }
            }
        }

        // spring and summer
        for(int r=1; r<=N; r++){
            for(int c=1; c<=N; c++){
                if(tree[r][c].size() > 0){
                    for(int idx=0; idx<tree[r][c].size(); idx++){
                        if(grid[r][c] >= tree[r][c][idx]){
                            grid[r][c] -= tree[r][c][idx];
                            tree[r][c][idx]++;
                        }
                        else{
                            for(int ridx = tree[r][c].size()-1; ridx >= idx; ridx--){
                                grid[r][c] += tree[r][c][ridx]/2;
                                tree[r][c].pop_back();
                            }
                        }
                    }
                }
            }
        }

        // fall and windter
        for(int r=1; r<=N; r++){
            for(int c=1; c<=N; c++){
                grid[r][c] += A[r][c]; 
                if(tree[r][c].size() > 0){
                    for(int idx=0; idx<tree[r][c].size(); idx++){
                        if(tree[r][c][idx] % 5 == 0){
                            for(int i=0; i<8; i++){
                                int nr = r + dr[i];
                                int nc = c + dc[i];
                                if(nr<1 || nr>N || nc<1 || nc>N) continue;
                                tree[nr][nc].push_back(1);
                            }
                        }
                    }
                }
            }
        }
        year++;
    }

    int cnt = 0;
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            if(tree[r][c].size() > 0) cnt += tree[r][c].size();
        }
    }

    cout << cnt << "\n";

}