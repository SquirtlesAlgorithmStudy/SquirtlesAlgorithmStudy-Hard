#include <iostream>
#include <vector>

using namespace std;
int N;

int main(){
    cin >> N;

    vector<int> dp(N+2); // N=1일 경우를 방지해 dp(N+2)

    dp[1]=1; dp[2] = 2;
    for(int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N]%10007 << endl;
}