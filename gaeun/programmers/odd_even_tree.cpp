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
        for(int j=0; j<treeToCheck.size(); j++){
            int forwardNode = 0;
            int reverseNode = 0;
            for(int k=0; k<treeToCheck.size(); k++){
                if(k==j){
                    if(treeToCheck[k]%2 == graph[treeToCheck[k]].size()%2) forwardNode++;
                    else reverseNode++;
                }
                else{
                    if(treeToCheck[k]%2 == (graph[treeToCheck[k]].size()-1)%2) forwardNode++;
                    else reverseNode++;
                }
            }
        if(forwardNode == 0) reverseTree++;
        if(reverseNode == 0) forwardTree++;
        }
    }

    answer.push_back(forwardTree);
    answer.push_back(reverseTree);

    return answer;
}