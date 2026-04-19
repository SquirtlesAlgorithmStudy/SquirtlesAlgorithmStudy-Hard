#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> dp(5001, INT_MAX);

int main(){
    cin >> N;

    dp[0] = 0;
    for(int i=0; i<=N; i++){
        if(dp[i] == INT_MAX) continue;
        if(i+3 <= N) dp[i+3] = min(dp[i+3], dp[i]+1);
        if(i+5 <= N) dp[i+5] = min(dp[i+5], dp[i]+1);
    }

    if(dp[N] == INT_MAX) cout << -1;
    else cout << dp[N] << endl;
}