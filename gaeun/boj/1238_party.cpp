#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int N, M, X;
vector<pair<int,int>> graph[2][1001]; // graph[0]: forward, graph[1]: reverse
vector<int> d[2]; 
vector<int> totalTime;

void dijkstra(int start, int dir){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    d[dir][start] = 0;

    while(!pq.empty()){
        int currNode = pq.top().second;
        int distToCurrNode = pq.top().first;
        pq.pop();

        if(distToCurrNode > d[dir][currNode]) continue;

        for(int i=0; i<graph[dir][currNode].size(); i++){
            int newDist = distToCurrNode + graph[dir][currNode][i].second;
            if(newDist < d[dir][graph[dir][currNode][i].first]){
                d[dir][graph[dir][currNode][i].first] = newDist;
                pq.push({newDist,graph[dir][currNode][i].first});
            }
        }      
    }
}

// 최적화
int main(){
    cin >> N >> M >> X;
    totalTime.assign(N+1, 0);

    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[0][a].push_back({b,c});
        graph[1][b].push_back({a,c});
    }

    d[0].assign(N+1, INT_MAX);
    d[1].assign(N+1, INT_MAX);

    // 각 노드에서 X까지의 최단거리 = 역방향 그래프를 이용한 X에서 각 노드까지의 최단거리
    dijkstra(X, 1); 

    // 돌아올때
    dijkstra(X, 0);

    int answer = 0;
    for(int i=1; i<=N; i++){
        answer = max(answer, d[0][i] + d[1][i]);
    }

    cout << answer << "\n";

}

// 최적화 x
// int main(){
//     cin >> N >> M >> X;
//     totalTime.assign(N+1, 0);

//     for(int i=0; i<M; i++){
//         int a,b,c;
//         cin >> a >> b >> c;
//         graph[0][a].push_back({b,c});
//         graph[1][b].push_back({a,c});
//     }


//     // X로 갈 때
//     for(int i=1; i<=N; i++){
//         d.assign(N+1, INT_MAX);
//         dijkstra(i);
//         totalTime[i] = d[X];
//     }

//     // 돌아올때
//     d.assign(N+1, INT_MAX);
//     dijkstra(X);
//     for(int i=1; i<=N; i++){
//         totalTime[i] += d[i];
//     }

//     cout << *max_element(totalTime.begin(), totalTime.end()) << "\n";

// }