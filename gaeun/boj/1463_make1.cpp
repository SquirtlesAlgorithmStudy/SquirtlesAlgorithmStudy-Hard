#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> dp(1000001, INT_MAX);

int main(){
    cin >> N;

    dp[1] = 0;
    for(int i=1; i<=N; i++){
        if(dp[i] == INT_MAX) continue;

        if(i*3 <= N) dp[i*3] = min(dp[i*3], dp[i]+1);
        if(i*2 <= N) dp[i*2] = min(dp[i*2], dp[i]+1);
        if(i+1 <= N) dp[i+1] = min(dp[i+1], dp[i]+1);
    }

    cout << dp[N];
}