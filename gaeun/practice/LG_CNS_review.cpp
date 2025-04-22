#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N,M,T,S,E;
vector<vector<int>> graphBefore;
vector<vector<int>> graphAfter;
struct info{
    int node;
    int distFromS;
    int distToE;
};
vector<info> prepass;
bool compare(info a, info b){
    if(a.distFromS != b.distFromS) return a.distFromS < b.distFromS;
    if(a.distToE != b.distToE) return a.distToE < b.distToE;
    return a.node < b.node;
}

void calcDistFromS(info& in){
    queue<pair<int,int>> q;
    vector<bool> visited(N+1, 0);

    q.push({S,0});
    visited[S] = 1;

    while(!q.empty()){
        pair<int,int> curr = q.front(); q.pop();
        if(curr.first == in.node){
            in.distFromS = curr.second;
            return;
        }

        for(int i=0; i<graphBefore[curr.first].size(); i++){
            if(visited[graphBefore[curr.first][i]]) continue;
            q.push({graphBefore[curr.first][i], curr.second+1});
            visited[graphBefore[curr.first][i]] = 1;
        }
    }
}

void calcDistToE(info& in){
    queue<pair<int,int>> q;
    vector<bool> visited(N+1, 0);

    q.push({in.node,0});
    visited[in.node] = 1;

    while(!q.empty()){
        pair<int,int> curr = q.front(); q.pop();
        if(curr.first == E){
            in.distToE = curr.second;
            return;
        }

        for(int i=0; i<graphAfter[curr.first].size(); i++){
            if(visited[graphAfter[curr.first][i]]) continue;
            q.push({graphAfter[curr.first][i], curr.second+1});
            visited[graphAfter[curr.first][i]] = 1;
        }
    }
}

int main(){
    cin >> N >> M >> T >> S >> E;
    for(int i=0; i<T; i++){
        int a;
        cin >> a;

        info in;
        in.node = a;
        in.distFromS = INT_MAX;
        in.distToE = INT_MAX;

        prepass.push_back(in);
    }

    graphAfter.resize(N+1);
    graphBefore.resize(N+1);
    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        graphBefore[s].push_back(e);
        graphAfter[s].push_back(e);
        graphAfter[e].push_back(s);
    }

    for(int i=0; i<prepass.size(); i++){
        calcDistFromS(prepass[i]);
        calcDistToE(prepass[i]);
    }

    sort(prepass.begin(), prepass.end(), compare);

    if(prepass[0].distFromS == INT_MAX || prepass[0].distToE == INT_MAX) cout << "-1\n";
    else cout << prepass[0].node << " " << prepass[0].distFromS + prepass[0].distToE << "\n";
}