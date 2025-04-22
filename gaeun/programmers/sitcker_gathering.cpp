#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int N = sticker.size();
    vector<int> dp(N, 0);
    
    // start from [0]
    dp[0] = sticker[0];
    for(int i=0; i<=N-4; i++){
        if(i==1) continue;
        
        dp[i+2] = max(dp[i+2], dp[i] + sticker[i+2]);
        
        if(i+3 == N-1) continue;
        dp[i+3] = max(dp[i+3], dp[i] + sticker[i+3]);
    }
    answer = *max_element(dp.begin(), dp.end());
    answer = max(answer, *max_element(dp.begin(), dp.end()));
    cout << "first dp: ";
    for(int n:dp) cout << n << " ";
    cout << "\n";

    
    // start from [1]
    dp.assign(N,0);
    dp[1] = sticker[1];
    for(int i=1; i<=N-3; i++){
        if(i == 2) continue;
        cout << "i: " << i << "dp[i+2]: " << dp[i+2] << "dp[i] + sticker[i+2]: " << dp[i] + sticker[i+2] << "\n";
        dp[i+2] = max(dp[i+2], dp[i] + sticker[i+2]);
        
        if(i+3 >= N) continue;
        dp[i+3] = max(dp[i+3], dp[i] + sticker[i+3]);
    }
    answer = max(answer, *max_element(dp.begin(), dp.end()));
    cout << "second dp: ";
    for(int n:dp) cout << n << " ";
    cout << "\n";

    return answer;
}

int main(){
    int n;
    cin >> n;

    vector<int> sticker;
    for(int i=0; i<n; i++){
        int s;
        cin >> s;
        sticker.push_back(s);
    }

    cout << solution(sticker) << "\n";
}