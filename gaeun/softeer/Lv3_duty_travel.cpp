#include<iostream>
#include<vector> // pair
#include<algorithm> // sort()

using namespace std;

int N, M;
string father="";
vector<vector<pair<int,char>>> graph;
bool visited[5001] = {0,};
string str = "";
int answer = 0;
vector<vector<int>> dp;


void dfs(int node){    
    int curr = node;
    visited[curr] = 1;

    // leaf node 도착하면 문자열 저장
    if(curr != 1 && graph[curr].size() == 1){
        int lcs_length = lcs(str);
        answer = max(answer, lcs_length);
        //cout << "str: " << str << " lcs: " << lcs_length << endl;
        return;
    }

    for(int i=0; i<graph[curr].size(); i++){
        int next = graph[curr][i].first;
        if(!visited[next]){
            str += graph[curr][i].second;
            dfs(next);
        }
        else continue; // 방문 되었던 노드에 대해 str.pop_back()이 수행되지 않도록
        if(!str.empty()) str.pop_back(); // if문 들어가서 dfs 수행하고 terminate할때만 str에서 가장 뒷자리 문자 삭제. 
    }
}

int main(int argc, char** argv)
{
    cin >> N >> M;
    cin >> father;

    graph.resize(N+1);

    dp.resize(M, vector<int>(father.size()));
    for(int i=0; i<=M; i++){
        for(int j=0; j<=father.size(); j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }   
    }

    for(int i=0; i<N-1; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;

        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }

    dfs(1);

    cout << answer << endl;

   return 0;
}