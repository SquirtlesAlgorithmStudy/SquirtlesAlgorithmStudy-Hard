#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int N = sticker.size();
    vector<int> dp(N, 0);
    
    // w/o the last sticker
    dp[0] = sticker[0];
    dp[1] = sticker[1];
    for(int i=0; i<=N-4; i++){        
        dp[i+2] = max(dp[i+2], dp[i] + sticker[i+2]);
        
        if(i+3 == N-1) continue;
        dp[i+3] = max(dp[i+3], dp[i] + sticker[i+3]);
    }
    answer = *max_element(dp.begin(), dp.end());
    
    // w/ the last sticker
    dp.assign(N,0);
    dp[1] = sticker[1];
    dp[2] = sticker[2];
    for(int i=1; i<=N-3; i++){
        dp[i+2] = max(dp[i+2], dp[i] + sticker[i+2]);
        
        if(i+3 >= N) continue;
        dp[i+3] = max(dp[i+3], dp[i] + sticker[i+3]);
    }
    answer = max(answer, *max_element(dp.begin(), dp.end()));

    return answer;
}