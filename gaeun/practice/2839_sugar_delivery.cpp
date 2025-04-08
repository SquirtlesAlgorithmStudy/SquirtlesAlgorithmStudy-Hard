#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt = 0;
int dp[5001] = {0, };

// dp
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    dp[3] = 1; dp[5] = 1;
    for(int i=6; i<=N; i++){
        if(dp[i-3] > 0) dp[i] = dp[i-3]+1;
        if(dp[i-5] > 0) dp[i] = (dp[i]==0)? dp[i-5]+1 : min(dp[i], dp[i-5]+1);
    }

    if(dp[N] == 0) cout << -1 << "\n";
    else cout << dp[N] << "\n";

}

// greedy
// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     cin >> N;

//     while(1){
//         if(N == 0) break;

//         if(N>=5){
//             if(N%5 == 0){
//                 N -= 5;
//             }   
//             else if(N%3 == 0){
//                 N -= 3;
//             }
//             else{
//                 N -= 5;
//             }
//             cnt++;
//         } 
//         if(N>=3 && N<5){
//             N -= 3;
//             cnt++;
//         } 
//         if(N != 0 && N<3){
//             cnt = -1;
//             break;
//         }
//     }

//     cout << cnt << "\n";
// }