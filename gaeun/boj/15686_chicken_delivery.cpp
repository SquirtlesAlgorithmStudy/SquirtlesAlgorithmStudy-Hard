#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int grid[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> chickenSelected;
int minCityDist = INT_MAX;

void calcDist(){
    int cityDist = 0;
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            if(grid[r][c] == 1){
                int chickenDist = INT_MAX;
                for(int i=0; i<M; i++){
                    int dist = abs(r-chickenSelected[i].first) + abs(c-chickenSelected[i].second);
                    chickenDist = min(chickenDist, dist);
                }
                cityDist += chickenDist;
            }
        }
    }
    minCityDist = min(minCityDist, cityDist);
}

void dfs(int s_i, int cnt){
    if(cnt == M){
        calcDist();
        return;
    }
    else{
        for(int i=s_i; i<chicken.size(); i++){
            chickenSelected.push_back(chicken[i]);
            dfs(i+1, cnt+1);
            chickenSelected.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }

    dfs(0,0);

    cout << minCityDist << "\n";

}