#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;
int answer = -1;

// top-down
void makeDP(int curr, int cnt){
    if(dp[curr]!=0 && dp[curr]<=cnt) return; 

    dp[curr] = cnt;

    if(curr == N) answer = dp[curr];

    if(curr+3 <= N) makeDP(curr+3, cnt+1);
    if(curr+5 <= N) makeDP(curr+5, cnt+1);
}

int main(){
    cin >> N;
    dp.resize(N+1);

    makeDP(0, 0);
    cout << answer << endl;
}