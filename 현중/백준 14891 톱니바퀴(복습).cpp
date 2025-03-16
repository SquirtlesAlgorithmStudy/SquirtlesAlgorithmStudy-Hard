// 백준 14891 톱니바퀴(복습)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> gear(4);
vector<int> directions(4);

// 1. 시계 =1 / 반시계 = -1
void rotate_gear(int idx, int dir)
{
    if (dir == 1)
    {
        char last = gear[idx].back();
        gear[idx].pop_back();
        gear[idx] = last + gear[idx];
    }
    else if (dir == -1)
    {
        char first = gear[idx].front();
        gear[idx].erase(gear[idx].begin());
        gear[idx] = gear[idx] + first;
    }
}

// 2. 회전방향을 결정하는 함수
void decide_directions(int idx, int dir)
{
    directions[idx] = dir;
    // 하나를 기준으로 왼쪽은?
    for (int i = idx - 1; i >= 0; i--)
    {
        if (gear[i][2] != gear[i + 1][6])
        {
            directions[i] = -directions[i + 1];
        }
        else
        {
            break;
        }
    }

    // 하나를 기준으로 오른쪽은?
    for (int i = idx + 1; i < 4; i++)
    {
        if (gear[i][6] != gear[i - 1][2])
        {
            directions[i] = -directions[i - 1];
        }
        else
        {
            break;
        }
    }
}

void execute_rotation()
{
    for (int i = 0; i < 4; i++)
    {
        if (directions[i] != 0)
        {
            rotate_gear(i, directions[i]);
        }
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> gear[i];
    }

    int K; // 회전회수
    cin >> K;

    for (int i = 0; i < K; i++)

    {
        int gear_idx, direction;
        cin >> gear_idx >> direction;

        gear_idx -= 1;

        directions = {0, 0, 0, 0};
        decide_directions(gear_idx, direction);

        execute_rotation();
    }

    int result = 0;
    // 우리의 목적은 K번 회전 후 12시 방향의 값
    if (gear[0][0] == '1')
    {
        result += 1;
    }
    if (gear[1][0] == '1')
    {
        result += 2;
    }
    if (gear[2][0] == '1')
    {
        result += 4;
    }
    if (gear[3][0] == '1')
    {
        result += 8;
    }

    cout << result << endl;

    return 0;
}