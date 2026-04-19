#include <iostream>
#include <climits>
#include <string>
#include <queue>

using namespace std;

int ans = INT_MAX;
int map[1001][1001] = {0,};
int visited[1001][1001][2] = {0,}; // [0]: broken wall dimension, [1]: normal dimension
int dr[4] = {-1, 1, 0, 0}; // 상하좌우
int dc[4] = {0, 0, -1, 1};
int N, M;

struct nodeInfo{
    int r;
    int c;
    bool isBreakPossible;
};

int bfs(nodeInfo startNode){
    queue<nodeInfo> q;
    q.push(startNode);
    visited[startNode.r][startNode.c][1] = 1;

    while(!q.empty()){
        nodeInfo curr = q.front();
        q.pop();

        if(curr.r == N && curr.c == M) return visited[curr.r][curr.c][curr.isBreakPossible];

        for(int i=0; i<4; i++){
            nodeInfo next;
            next.r = curr.r + dr[i];
            next.c = curr.c + dc[i];

            if(next.r<=0 || next.r>N || next.c<=0 || next.c>M) continue;
            if(map[next.r][next.c]==1 && curr.isBreakPossible==0) continue;

            if(map[next.r][next.c]==0){
                next.isBreakPossible = curr.isBreakPossible;
            }
            else if(map[next.r][next.c]==1 && curr.isBreakPossible==1){
                next.isBreakPossible = 0;
            }

            if(visited[next.r][next.c][next.isBreakPossible]) continue;

            q.push(next);
            visited[next.r][next.c][next.isBreakPossible] = visited[curr.r][curr.c][curr.isBreakPossible] + 1;
        }
    }
    return -1;
}

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
        for(int j=1; j<=M; j++){
            map[i][j] = s[j-1] - '0';
        }
    }

    nodeInfo startNode = {1, 1, 1};
    int answer = bfs(startNode);
    cout << answer << endl;
}