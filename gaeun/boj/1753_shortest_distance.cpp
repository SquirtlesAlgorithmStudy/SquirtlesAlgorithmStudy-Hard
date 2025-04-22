#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int V,E;
vector<vector<pair<int,int>>> graph;
vector<int> dist;
int start;

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int distToCurrNode = pq.top().first;
        pq.pop();

        if(distToCurrNode > dist[node]) continue;

        for(int i=0; i<graph[node].size(); i++){
            int newDist = distToCurrNode + graph[node][i].second;
            if(newDist < dist[graph[node][i].first]){
                dist[graph[node][i].first] = newDist;
                pq.push({newDist, graph[node][i].first}); 
            }
        }
    }
}

int main(){
    cin >> V >> E;
    cin >> start;

    graph.resize(V+1);
    dist.assign(V+1, INT_MAX);
    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({v,w});
    }

    dijkstra(start);

    for(int i=1; i<=V; i++){
        if(dist[i] != INT_MAX) cout << dist[i] << "\n";
        else cout << "INF" << "\n";
    }

}