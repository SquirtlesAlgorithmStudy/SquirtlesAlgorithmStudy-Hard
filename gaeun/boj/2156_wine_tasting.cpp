#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> wine;
vector<int> dp;

int main(){
    cin >> N;

    wine.resize(N+1,0);
    dp.resize(N+1,0);
    for(int i=1; i<=N; i++){
        cin >> wine[i];
    }

    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    for(int i=3; i<=N; i++){
        dp[i] = max(dp[i-1], max(dp[i-3]+wine[i-1]+wine[i], dp[i-2]+wine[i]));
    }

    cout << dp[N] << "\n";
}