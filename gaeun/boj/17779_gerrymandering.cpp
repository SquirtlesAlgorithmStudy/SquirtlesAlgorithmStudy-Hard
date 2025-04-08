#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int grid[21][21];
int minDiff = INT_MAX;

void calc_people(int x, int y, int d1, int d2){
    int visited[21][21] = {0, };
    vector<int> sum(5,0);
    int debugging[21][21];

    // 5선거구
    for(int i=0; i<=d1; i++){
        sum[4] += grid[x+i][y-i];
        visited[x+i][y-i] = 1;
        debugging[x+i][y-i] = 5;
    }
    for(int i=1; i<=d2; i++){
        sum[4] += grid[x+i][y+i];
        visited[x+i][y+i] = 1;
        debugging[x+i][y+i] = 5;
    }
    for(int i=1; i<=d2; i++){
        sum[4] += grid[x+d1+i][y-d1+i];
        visited[x+d1+i][y-d1+i] = 1;
        debugging[x+d1+i][y-d1+i] = 5;
    }
    for(int i=1; i<d1; i++){
        sum[4] += grid[x+d2+i][y+d2-i];
        visited[x+d2+i][y+d2-i] = 1;
        debugging[x+d2+i][y+d2-i] = 5;
    }
    for(int i=x+1; i<x+d1+d2; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(visited[i][j] == 1) cnt++;
            if(cnt == 1 && !visited[i][j]){
                visited[i][j] = 1;
                sum[4] += grid[i][j];
                debugging[i][j] = 5;
            } 
        }
    }

    // 1선거구
    for(int i=1; i<x+d1; i++){
        for(int j=1; j<=y; j++){
            if(!visited[i][j]){
                sum[0] += grid[i][j];
                debugging[i][j] = 1;
            }             
        }
    }

    // 2선거구
    for(int i=1; i<=x+d2; i++){
        for(int j=y+1; j<=N; j++){
            if(!visited[i][j]){
                sum[1] += grid[i][j];
                debugging[i][j] = 2;
            } 
        }
    }

    // 3선거구
    for(int i=x+d1; i<=N; i++){
        for(int j=1; j<y-d1+d2; j++){
            if(!visited[i][j]){
                sum[2] += grid[i][j];
                debugging[i][j] = 3;
            } 
        }
    }

    // 4선거구
    for(int i=x+d2+1; i<=N; i++){
        for(int j=y-d1+d2; j<=N; j++){
            if(!visited[i][j]){
                sum[3] += grid[i][j];
                debugging[i][j] = 4;
            } 
        }
    }

    int diff = *max_element(sum.begin(), sum.end()) - *min_element(sum.begin(), sum.end());
    minDiff = min(minDiff, diff);

    // cout << "x, y, d1, d2: " << x << ", " << y << ", " << d1 << ", " << d2 << "\n";
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout << debugging[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i:sum) cout << i << " ";
    // cout << "\n";
    // cout << "diff: " << diff << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }
    }

    for(int x=1; x<=N-2; x++){
        for(int y=2; y<=N-1; y++){
            for(int d1=1; d1<=N-1; d1++){
                for(int d2=1; d2<=N-1; d2++){
                    if(y-d1<1 || y+d2>N || x+d1+d2>N) continue;
                    calc_people(x,y,d1,d2);
                }
            }
        }
    }

    cout << minDiff << "\n";
}