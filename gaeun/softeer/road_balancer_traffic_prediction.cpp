// 이 방식은 왜 틀릴까? -> 아래에 반례. 

// #include <iostream>
// #include <vector>

// using namespace std;
// using ll = long long;

// ll N, K;
// vector<ll> result;

// int main(){
//     cin >> N >> K;
//     result.resize(N+1);
//     result[1] = K;

//     for(int i=1; i<=N; i++){
//         int r; // max 50만 -> int 가능
//         cin >> r;

//         if(r > 0){
//             vector<int> p;
//             for(int j=0; j<r; j++){
//                 int pi; // max 10만 -> int 가능
//                 cin >> pi;
//                 p.push_back(pi);
//             }
//             ll req = result[i];
//             ll quo = req/r;
//             ll rem = req%r;
//             if(quo > 0){
//                 for(int j=0; j<r; j++){
//                     result[p[j]] += quo; 
//                 }
//             }            
//             for(int j=0; j<rem; j++){
//                 result[p[j]] += 1;
//             }
//         }
//     }

//     for(int i=1; i<=N; i++){
//         cout << result[i] << " ";
//     }
//     cout << endl; 
// }

// 반례: 
// 10 999
// 3 2 5 8
// 2 9 10
// 0
// 0
// 3 2 4 3
// 0
// 0
// 2 6 7
// 0
// 0
// node 9의 경우 2로부터 167, 5로부터 56개를 받아서 223, node 10의 경우 2로부터 166, 5로부터 55개를 받아서 221이 되어야 함.
// 하지만 위의 코드는 5에서 2로 보낸걸 다시 node 9, 10으로 분배하는 로직이 빠져있어서 불가능. 
// 즉, node 2를 node 5보다 빨리 처리하게 되어서 문제가 발생하는 것.
// -> 위상정렬로 처리해야하는 node 순서를 정렬하고, 트래픽을 분배하자. 

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

ll N, K;
vector<vector<ll>> tree;
vector<ll> indegree;
vector<ll> sequence;
vector<ll> result;

void topological_sort(){
    queue<int> q;
    q.push(1); // node 1
    while(!q.empty()){
        // 하나 꺼내고
        int current = q.front();
        sequence.push_back(current); // 정렬된 순서 저장
        q.pop();
        
        // 자식 노드와의 간선 삭제
        for(int i=0; i<tree[current].size(); i++){
            indegree[tree[current][i]]--;

            // 만약 진입차수가 0이 되면 q에 추가
            if(indegree[tree[current][i]] == 0) q.push(tree[current][i]);
        }
    }
}

int main(){
    cin >> N >> K;
    tree.resize(N+1);
    result.resize(N+1, 0); // use idx 1~N
    result[1] = K;
    indegree.resize(N+1, 0);

    for(int i=1; i<=N; i++){
        int r; // max 50만 -> int 가능
        cin >> r;

        if(r > 0){
            vector<ll> tmp;
            for(int j=0; j<r; j++){
                int pi; // max 10만 -> int 가능
                cin >> pi;
                tree[i].push_back(pi);
                indegree[pi]++;
            }
        }
    }

    topological_sort();

    for(int i=0; i<N; i++){
        int node = sequence[i];

        if(tree[node].size() > 0) // load balancer라면 분배
        {
            ll req = result[node];
            ll quo = req / tree[node].size();
            ll rem = req % tree[node].size();

            if(quo > 0){
                for(int j=0; j<tree[node].size(); j++){
                    result[tree[node][j]] += quo; 
                }
            }            
            for(int j=0; j<rem; j++){
                result[tree[node][j]] += 1;
            }
        }        
    }

    for(int i=1; i<=N; i++){
        cout << result[i] << " ";
    }
    cout << endl; 
}