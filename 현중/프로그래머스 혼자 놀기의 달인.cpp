// 프로그래머스 혼자 놀기의 달인

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int score(vector<int> cards, vector<bool> open, int i, int group)
{
    int idx = i;
    int count = 0;

    while (true)
    {
        if (!open[idx])
        {
            open[idx] = true;
            idx = cards[idx] - 1; // 현재 상자 idx = card에 적힌 숫자 -1 후 다음 idx로 이동
            count++;              // 현재 그룹에 속한 상자의 개수
        }
        else
            break;
    }

    // 모든 상자를 다 열었을 경우
    if (count >= cards.size())
        return 0;
    else if (group == 2) // 두번째 그룹 탐색 중인 경우
        return count;

    int max = 0;

    for (int i = 0; i < cards.size(); i++)
    {
        if (!open[i])
        {
            idx = i;
            int sum = score(cards, open, idx, 2);

            if (max < sum)
                max = sum;
        }
    }

    return count * max;
}

int main(vector<int> cards)
{
    int answer = 0;

    vector<bool> open;

    for (int i = 0; i < cards.size(); i++)
    {
        open.push_back(false);
    }

    for (int i = 0; i < cards.size(); i++)
    {
        int sum = score(cards, open, i, 1);
        if (answer < sum)
            answer = sum;
    }

    return answer;
}