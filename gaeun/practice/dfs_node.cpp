#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool visited[9] = {0,};
vector<int> graph[9];

void clear_visited(){
    for(int i=0; i<9; i++){
        visited[i] = 0;
    }
}

void dfs_recursion(int node){
    int curr = node;
    visited[node] = true;

    cout << "node: " << curr << endl;

    for (int i = 0; i < graph[curr].size(); i++)
    {
        int next = graph[curr][i];
        if (!visited[next])
            dfs_recursion(next);
    }
}

stack<int> s;
void dfs_stack(int node){
    s.push(node);
    visited[node] = true;

    while(!s.empty()){
        int curr = s.top();
        s.pop();

        cout << "curr: " << curr << endl;

        for(int i=graph[curr].size()-1; i>=0; i--){
            int next = graph[curr][i];
            if(!visited[next]){
                s.push(next);
                visited[next] = true;
            }
        }
    }    
}

int main(){
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);
    
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs_recursion(1);
    clear_visited();
    dfs_stack(1);


}