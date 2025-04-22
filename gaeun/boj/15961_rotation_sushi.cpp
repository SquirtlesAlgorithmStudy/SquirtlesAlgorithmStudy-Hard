#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, d, k, c;
vector<int> sushiList;
vector<int> visited;

int main(){
    cin >> N >> d >> k >> c;
    visited.assign(d+1, 0);

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        sushiList.push_back(n);
    }

    int cnt = 1; // 쿠폰을 먹을 수 있는 한종류    
    visited[c] = 1;

    for(int i=0; i<k; i++){
        if(visited[sushiList[i]] == 0) cnt++;
        visited[sushiList[i]]++;
    }
    int answer = cnt;

    for(int i=1; i<N; i++){
        // cout << "deleted sushiList: " << sushiList[i-1] << ", visited: " << visited[sushiList[i-1]] << "\n";
        visited[sushiList[i-1]]--;
        if(visited[sushiList[i-1]] == 0) cnt --;

        int idx = (i+k-1 >= N) ? (i+k-1)%N : i+k-1;
        // cout << "added sushiList: " << sushiList[idx] << ", visited: " << visited[sushiList[idx]] << "\n";
        if(visited[sushiList[idx]] == 0) cnt++;
        visited[sushiList[idx]]++;

        // cout << "cnt: " << cnt << "\n";
        answer = max(answer, cnt);
    }

    cout << answer << "\n";
}