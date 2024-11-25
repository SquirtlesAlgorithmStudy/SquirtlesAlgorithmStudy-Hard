// 모두 0으로 만들기

#include <iostream>
#include <vector>
#include <cmath> // abs() 사용
using namespace std;

long long dfs(int node, int parent, vector<long long> &a, vector<vector<int>> &graph, long long &moves)
{
    long long total = a[node]; // 현재 노드의 값

    for (int neighbor : graph[node])
    {
        if (neighbor == parent)
            continue;                                  // 부모 노드로는 되돌아가지 않음
        total += dfs(neighbor, node, a, graph, moves); // 자식 노드에서 값을 가져옴
    }

    moves += abs(total); // 현재 노드에서 전달하는 값의 절댓값만큼 이동 횟수 증가
    return total;        // 부모 노드로 전달할 값 반환
}

long long solution(vector<int> a, vector<vector<int>> edges)
{
    long long totalSum = 0;
    vector<long long> aLong(a.begin(), a.end()); // int -> long long 변환 (값 범위 고려)
    vector<vector<int>> graph(a.size());

    // 그래프 생성
    for (const auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // 노드 값의 총합 계산
    for (int val : a)
    {
        totalSum += val;
    }

    // 트리의 총합이 0이 아니라면 불가능
    if (totalSum != 0)
        return -1;

    long long moves = 0;             // 이동 횟수 누적
    dfs(0, -1, aLong, graph, moves); // 루트 노드에서 DFS 시작
    return moves;
}

int main()
{
    // 입력 받기
    int n; // 노드 개수
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // 노드 값 입력
    }

    int m = n - 1; // 간선의 개수
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1]; // 간선 정보 입력
    }

    // 결과 출력
    cout << solution(a, edges) << endl;
    return 0;
}
