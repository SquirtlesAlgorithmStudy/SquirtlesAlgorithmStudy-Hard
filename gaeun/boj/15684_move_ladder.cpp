#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N,M,H;
bool visited[31][11];
int maxDepth = 4;

bool move(){
    // 특정 사다리 기준으로
    for(int j=1; j<=N; j++){
        int curr = j;
        // 열 따라 내려가기
        for(int i=1; i<=H; i++){
            if(visited[i][curr]) curr++; // 여기서 curr을 증가시키기 때문에
            else if(visited[i][curr-1]) curr--; // 이건 꼭 else if로 써줘야한다..
        }
        if(curr != j) return false; // 하나라도 틀린거 나오면 false. 
    }
    return true;
}

void dfs(int start_i, int start_j, int cnt){
    if(cnt == maxDepth) return;

    if(move())maxDepth = cnt;
    else{
        for(int i=start_i; i<=H; i++){
            int j = (i==start_i) ? start_j : 1;
            for(; j<N; j++){
                if(!visited[i][j] && !visited[i][j-1] && !visited[i][j+1]){
                    visited[i][j] = 1;
                    dfs(i, j+1, cnt+1);
                    visited[i][j] = 0;
                }
            }
        }
    }  
}

int main(){
    cin >> N >> M >> H;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        visited[a][b] = 1;
    }

    dfs(1,1,0);
    if(maxDepth == 4) cout << -1 << endl;
    else cout << maxDepth << endl;

}