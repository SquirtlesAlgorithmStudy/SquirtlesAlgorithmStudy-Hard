#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

int N, M;
int visited[101];
vector<vector<int>> graph;
int dist[101][101];
int kevin[101] = {0,};

void bfs(int v){
    queue<pair<int, int>> q;
    q.push({v,0});
    visited[v] = 1;
    dist[v][v] = 0;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        if(dist[v][curr.first] > curr.second){
            dist[v][curr.first] = curr.second;
            kevin[v] += curr.second;
        }

        for(auto ele : graph[curr.first]){
            if(visited[ele]) continue;
            q.push({ele, curr.second+1});
            visited[ele] = 1;
        }
    }
}

int main(){
    cin >> N >> M;
    graph.resize(N+1);
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dist[i][j] = INT_MAX;
        }
    }
    for(int i=1; i<=N; i++){
        bfs(i);
        memset(visited, 0, sizeof(visited));
    }

    int minCnt = INT_MAX;
    int answer;
    for(int i=1; i<=N; i++){
        if(kevin[i] < minCnt){
            minCnt = kevin[i];
            answer = i;
        }
    }

    cout << answer << endl;
}