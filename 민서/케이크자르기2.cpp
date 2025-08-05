#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
ll arr[2000];
ll dp[2000][2000];
ll ans;

ll dfs(int i, int j) {
    if (dp[i][j]) return dp[i][j];
    return dp[i][j] = max(
        arr[i] + (arr[(i+1)%N] < arr[j] ? dfs((i+1)%N, (j-1+N)%N) : dfs((i+2)%N, j)),
        arr[j] + (arr[i] < arr[(j-1+N)%N] ? dfs(i, (j-2+N)%N) : dfs((i+1)%N, (j-1+N)%N))
    );
}
int main() 
{
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if (N % 2) {
        for (int i = 0; i < N; i++) dp[i][i] = arr[i];
    } else {
        for (int i = 0; i < N; i++) dp[i][(i+1)%N] = max(arr[i], arr[(i+1)%N]);
    }
    for (int i = 0; i < N; i++) ans = max(dfs(i, (i-1+N)%N), ans);
    cout << ans;
    
    return 0;
}
