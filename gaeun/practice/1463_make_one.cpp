#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> dp;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    dp.resize(N+1, 0);

    dp[1] = 0; dp[2] = 1; dp[3] = 1;

    for(int i=4; i<=N; i++){
        dp[i] = dp[i/2]+1 + i%2;
        dp[i] = min(dp[i], dp[i/3]+1 + i%3);
        dp[i] = min(dp[i], dp[i-1]+1);
    }

    cout << dp[N] << "\n";    

}