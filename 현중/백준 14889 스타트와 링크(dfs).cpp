// 백준 14889 스타트와 링크

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int min_diff = 1e9;
vector<vector<int>> board;
vector<bool> team; // start = true / link = false

int calculate_team_score(const vector<int> &team_members)
{ // board의 내용이 바뀌지 않기 때문에 const, &를 사용하여 읽기전용으로 만들어 메모리 낭비 줄여
    int score = 0;
    for (int i = 0; i < team_members.size(); ++i)
    {
        for (int j = i + 1; j < team_members.size(); ++j)
        {
            score += board[team_members[i]][team_members[j]] + board[team_members[j]][team_members[i]];
        }
    }
    return score;
}

// 능력치 차이를 계산하는 dfs
void dfs(int idx, int count)
{ // start team을 count해서
    if (count == N / 2)
    {
        vector<int> start_team, link_team;
        for (int i = 0; i < N; ++i) // i 번째 사람
        {
            if (team[i]) // T 면 start_team
            {
                start_team.push_back(i);
            }
            else
            {
                link_team.push_back(i);
            }
        }

        int start_score = calculate_team_score(start_team);
        int link_score = calculate_team_score(link_team);
        int diff = abs(start_score - link_score);
        min_diff = min(min_diff, diff);

        return;
    }

    for (int i = idx; i < N; ++i)
    {
        if (!team[i])
        {
            team[i] = true;
            dfs(i + 1, count + 1);
            team[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    board.resize(N, vector<int>(N));
    team.resize(N, false);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    // 백트래킹을 이용해 팀을 나누고, 최소 차이 계산
    dfs(0, 0);

    cout << min_diff << endl;

    return 0;
}