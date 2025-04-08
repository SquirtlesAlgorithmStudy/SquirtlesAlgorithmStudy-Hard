#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int population[11];
vector<vector<int>> graph(11);
int visited[11] = {0,};
vector<int> selected;
int minDiff = INT_MAX;

vector<bool> testVisited(11, 0);
void dfs(int node, vector<int> v){
    testVisited[node] = 1;
    for(int i=0; i<graph[node].size(); i++){
        int next = graph[node][i];
        if(!testVisited[next] && (find(v.begin(), v.end(), next) != v.end())) dfs(next, v);
    }
}

bool test(vector<int> v){
    bool flag = true;
    testVisited.assign(testVisited.size(), 0);
    dfs(v[0], v);
    for(int i=0; i<v.size(); i++){
        if(!testVisited[v[i]]) flag = false;
    }   
    if(flag) return true;
    else return false;
}

void comb(int s_i, int depth){
    if(depth >= N-1) return;
    else{
        for(int i=s_i; i<=N; i++){
            if(!visited[i]){
                visited[i] = 1;
                selected.push_back(i);
                vector<int> other;
                for(int j=1; j<=N; j++){
                    if(!visited[j]) other.push_back(j);
                }
                if(test(selected) && test(other)){
                    int sum1=0, sum2=0;
                    for(int n:selected) sum1 += population[n];
                    for(int n:other) sum2 += population[n];
                    int diff = abs(sum1 - sum2);
                    minDiff = min(minDiff, diff);

                    cout << "selected nodes: ";
                    for(int n:selected) cout << n << " ";
                    cout << ", other nodes: ";
                    for(int n:other) cout << n << " ";
                    cout << ", diff: " << diff << "\n";
                    cout << "\n";
                }
                comb(i+1, depth+1);
                selected.pop_back();
                visited[i] = 0;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> population[i]; 
    }
    for(int i=1; i<=N; i++){
        int n;
        cin >> n;
        
        for(int j=0; j<n; j++){
            int g;
            cin >> g;
            graph[i].push_back(g);
        }
    }

    comb(1, 0);
    if(minDiff == INT_MAX) cout << -1 << endl;
    else cout << minDiff << endl;

}