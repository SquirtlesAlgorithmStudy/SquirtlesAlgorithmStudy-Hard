// 백준 14891 톱니바퀴
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> gears(4);   // 1: {1010101} 2: {1010101} 3: {1010101} 4: {1010101}
vector<int> directions(4); // {1 -1 1 -1}

// 1. 톱니바퀴 시계(1), 반시계(-1)회전하는 알고리즘
void rotate_gear(int idx, int dir)
{ // (1: 1) (2: -1) (3: 1) (4: -1)
    if (dir == 1)
    {                                  // 시계
        char last = gears[idx].back(); // {1010101} -> {101010 }
        gears[idx].pop_back();
        gears[idx] = last + gears[idx];
    }
    else if (dir == -1)
    {
        char first = gears[idx].front();
        gears[idx].erase(gears[idx].begin());
        gears[idx] = gears[idx] + first;
    }
}

// 2. 회전 방향을 결정하는 함수
void decide_directions(int idx, int dir)
{
    directions[idx] = dir;

    // 왼쪽에 있는 톱니바퀴들에 대한 회전 결정
    for (int i = idx - 1; i >= 0; i--)
    { //(idx = 1,2,3,4 왼쪽이니까 숫자가 작아짐)
        if (gears[i][2] != gears[i + 1][6])
        {
            directions[i] = -directions[i + 1];
        }
        else
        {
            break;
        }
    }

    // 오른쪽에 있는 톱니바퀴들에 대한 회전 결정
    for (int i = idx + 1; i < 4; ++i)
    { //(idx = 1,2,3,4 오른쪽이니까 숫자가 커짐)
        if (gears[i][6] != gears[i - 1][2])
        { // gears[4][8]
            directions[i] = -directions[i - 1];
        }
        else
        {
            break;
        }
    }
}
// 3. 실제 회전
void execute_rotation()
{
    for (int i = 0; i < 4; i++)
    { // 톱니바퀴 4개
        if (directions[i] != 0)
        {
            rotate_gear(i, directions[i]);
        }
    }
}

// 4. main
int main()
{
    // 1. 톱니바퀴 4개
    for (int i = 0; i < 4; i++)
    {
        cin >> gears[i];
    }

    int K; // 회전 횟수
    cin >> K;

    // k번 회전 명령 처리
    for (int i = 0; i < K; i++)
    {
        int gear_idx, direction;
        cin >> gear_idx >> direction;

        // gear_idx는 1번부터이기 때문에
        gear_idx -= 1;

        // 각 gears의 방향 초기화
        directions = {0, 0, 0, 0};
        decide_directions(gear_idx, direction);

        execute_rotation();
    }

    int result = 0;
    if (gears[0][0] == '1')
        result += 1; // '1' = S극 / '0' = N극
    if (gears[1][0] == '1')
        result += 2;
    if (gears[2][0] == '1')
        result += 4;
    if (gears[3][0] == '1')
        result += 8;

    cout << result << endl;

    return 0;
}
