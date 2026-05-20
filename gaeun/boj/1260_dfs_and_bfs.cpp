#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
bool visited[1001] = {0,};

void dfs(int v){
    cout << v << " ";
    visited[v] = 1;

    for(const auto& ele : graph[v]){
        if(visited[ele]) continue;
        dfs(ele);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();

        for(const auto& ele : graph[curr]){
            if(visited[ele]) continue;
            q.push(ele);
            visited[ele] = 1;
        }
    }
}

int main(){
    cin >> N >> M >> V;
    graph.resize(N+1);

    for(int i=0; i<M; i++){
        int n, m;
        cin >> n >> m;

        graph[n].push_back(m);
        graph[m].push_back(n);
    }
    
    for(int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    bfs(V);
}