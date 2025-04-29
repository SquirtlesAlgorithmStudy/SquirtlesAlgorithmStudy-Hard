#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, vector<int>> graph;
map<int, bool> visited;

vector<int> bfs(int node){
    vector<int> tree;
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int curr = q.front(); q.pop();
        tree.push_back(curr);

        for(int i=0; i<graph[curr].size(); i++){
            if(visited[graph[curr][i]]) continue;
            q.push(graph[curr][i]);
            visited[graph[curr][i]] = 1;
        }
    }
    return tree;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer;

    // make graph
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    // seperate each tree
    vector<vector<int>> group;
    for(int i=0; i<nodes.size(); i++){
        if(!visited[nodes[i]]){
            vector<int> tree = bfs(nodes[i]);
            group.push_back(tree);
        }
    }

    // find forward, reverse odd and even tree
    int reverseTree = 0;
    int forwardTree = 0;
    for(int i=0; i<group.size(); i++){
        vector<int> treeToCheck = group[i];
        int forwardNode = 0;
        int reverseNode = 0;
        for(int j=0; j<treeToCheck.size(); j++){
            if(treeToCheck[j]%2 == graph[treeToCheck[j]].size()%2) forwardNode++;
            else reverseNode++;                
        }
        if(forwardNode == 1) forwardTree++;
        if(reverseNode == 1) reverseTree++;
    }

    answer.push_back(forwardTree);
    answer.push_back(reverseTree);
    return answer;
}

int main(){
    vector<int> nodes = {9, 15, 14, 7, 6, 1, 2, 4, 5, 11, 8, 10};
    vector<vector<int>> edges = {{5, 14}, {1, 4}, {9, 11}, {2, 15}, {2, 5}, {9, 7}, {8, 1}, {6, 4}};

    vector<int> answer = solution(nodes, edges);

    cout << answer[0] << " " << answer[1] << "\n";
}