#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int T[16];
int P[16];
int dp[17];

int result = 0;

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=1; i<=N+1; i++){
        dp[i] = max(result, dp[i]); // 이전 결과 누적
        result = max(result, dp[i]);
        if(i+T[i]-1 <= N){
            if(i <= N) dp[i+T[i]] = max(P[i]+dp[i], dp[i+T[i]]);
        }
        
    }

    cout << result << endl;
}