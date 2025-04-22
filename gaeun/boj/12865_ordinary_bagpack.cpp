#include <iostream>
#include <vector>

using namespace std;

int N,K;
int W[101];
int V[101];
int dp[101][1000001] = {0,}; // dp[i][k]: 무게 제한이 k일때, 1~i번째 물건까지 고려했을때의 최대 가치

int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> W[i] >> V[i];
    }

    for(int k=1; k<=K; k++){ // 무게 제한이 k일 때
        for(int i=1; i<=N; i++){
            // i번째 물건 못담음 -> i-1번째까지의 최대값을 그대로
            if(W[i] > k) dp[i][k] = dp[i-1][k]; 

            // i번째 물건 담을 수 있음: i번째 물건을 담지 않는 것이 큰지, 담는 것이 더 큰지 비교. 
            // i번째 물건을 담는다 = 현재 무게 제한 k에서 i번째 물건의 무게를 뺀 열에서의 i-1행의 dp값에 i번째 물건의 가치를 더함. 
            else dp[i][k] = max(dp[i-1][k], dp[i-1][k-W[i]]+V[i]);
        }
    } // 최대값은 dp[N][K]에 저장. 

    cout << dp[N][K] << "\n";

}