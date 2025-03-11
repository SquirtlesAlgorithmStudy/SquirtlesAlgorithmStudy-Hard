// 백준 15686 치킨 배달

#include <iostream>
#include <vector>
#include <algorithm> // sort, min/max, count
#include <cmath>

using namespace std;

int N, M;                         // board, 수익을 많이내는 치킨집 갯수
vector<pair<int, int>> houses;    // 집의 좌표             {{0, 3}, {1, 0}, {2, 4}, {3, 1}, {4, 3}}
vector<pair<int, int>> chickens;  // 치킨집의 좌표          {{0, 1}, {2, 2}, {4, 0}};
vector<int> selected_chicken_idx; // 선택된 치킨집의 idx    {0 :{0, 1}, 1 :{2, 2}, 2 :{4, 0}};
int min_chicken_distance = 1e9;

// 3. 치킨 거리 계산 함수(집을 기준으로 정해지며)
int calculate_chicken_distance()
{
    int total_distance = 0;
    for (auto house : houses)
    { // for (pair<int, int> house : houses)
        int hx = house.first;
        int hy = house.second;
        int min_distance = 1e9; // 선택된 치킨집 - 각각의 집 거리
        for (int i : selected_chicken_idx)
        { // int i = 0; i < chickens.size(); ++i
            int cx = chickens[i].first;
            int cy = chickens[i].second;
            int distance = abs(hx - cx) + abs(hy - cy); // 선택된 치킨집 - 선택된 집
            min_distance = min(min_distance, distance); // 가장 가까운 치킨집 - 선택된 집
        }
        total_distance += min_distance;
    }
    return total_distance;
}

// 2. dfs를 사용하여 조합 생성 -> 반환하지 않기 때문에 int 아닌  void
void dfs(int idx, int count)
{ // 현재 치킨집의 idx, 현재까지 선택된 치킨집의 갯수
    if (count == M)
    {                                                                                   // 선택된 치킨집 수가 문제에서 주어진 M만큼 채웠다면,
        min_chicken_distance = min(min_chicken_distance, calculate_chicken_distance()); // 현재 선택된 치킨집 조합으로 모든집들에 대해서 계산
        return;
    }
    for (int i = idx; i < chickens.size(); ++i)
    { // chickens.size() = selected_chicken_idx
        selected_chicken_idx.push_back(i);
        dfs(i + 1, count + 1);
        selected_chicken_idx.pop_back(); // 백트래킹(이전 단계로 돌아가서 방금 선택한 치킨집을 제거)
    }
}

// 목표 : 치킨집을 최대 M개 골랐을 때, 도시의 치킨 거리의 최솟값!!!
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int value;
            cin >> value;
            if (value == 1)
            {
                houses.push_back({i, j});
            }
            else if (value == 2)
            {
                chickens.push_back({i, j});
            }
        }
    }

    // DFS를 통해 M개의 치킨집 선택
    dfs(0, 0);

    cout << min_chicken_distance << endl;
    return 0;
}