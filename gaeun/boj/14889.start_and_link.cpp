#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int grid[21][21];
int result = 100;

vector<int> team1;

// 살짝 향상: 탐색하면서 배열에 저장하는게 아니라, check표시를 해. 
// cnt == N/2 에서 체크표시 되어있는 것들의 합, 그렇지 않은 것들의 합 구해.
void bfs(int start, int cnt){
    if(cnt == N/2){
        vector<int> team2;
        for(int i=1; i<=N; i++){
            if(find(team1.begin(), team1.end(), i) == team1.end()) team2.push_back(i);
        }

        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                sum1 += grid[team1[i]][team1[j]];
                sum1 += grid[team1[j]][team1[i]];

                sum2 += grid[team2[i]][team2[j]];
                sum2 += grid[team2[j]][team2[i]];
            }
        }

        int difference = abs(sum1 - sum2);
        result = min(result, difference);

        // cout << "team1: ";
        // for(int i:team1) cout << i << " ";
        // cout << endl << "sum1: " << sum1 << endl;
        // cout << "team2: ";
        // for(int i:team2) cout << i << " ";
        // cout << endl << "sum2: " << sum2 << endl << endl;

        return;
    }
    else{
        for(int i=start; i<=N; i++){
            team1.push_back(i);
            bfs(i+1, cnt+1);
            team1.pop_back();
        }
    }
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }
    }

    bfs(1,0);

    cout << result << endl;
}