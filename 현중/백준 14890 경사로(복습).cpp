// 백준 14890 경사로(복습)

// 목표 : 길의 갯수 출력

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L; // 행=열의 크기, 경사로의 길이
vector<vector<int>> board;

bool Canpass(vector<int> &line)
{
    // 0. 사용여부확인
    vector<bool> used(N, false);

    for (int i = 0; i < N - 1; i++)
    {
        // 1. 높이가 같을 때
        if (line[i] == line[i + 1])
        {
            continue;
        }

        // 2. 만약 차이가 1보다 크면 설치 불가
        if (abs(line[i] - line[i + 1]) > 1)
            return false;

        // 3. 내려갈 때
        if (line[i] > line[i + 1])
        {
            for (int j = i + 1; j <= i + L; j++)
            {
                // 범위 밖인지 확인하고 범위 밖이면 false
                if (j >= N || used[j] || line[j] != line[i + 1])
                    return false;
                used[j] = true;
            }
        }
        // 4. 올라갈 때
        else
        {
            for (int j = i; j > i - L; --j)
            {
                if (j < 0 || used[j] || line[j] != line[i])
                    return false;
                used[j] = true;
            }
        }
    }

    return true;
}

int main()
{
    cin >> N >> L;
    board.resize(N, vector<int>(N)); // 각 행을 저장할 벡터

    // board입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    // 행 확인
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (Canpass(board[i]))
        {
            result++;
        }
    }

    // 열 확인
    for (int j = 0; j < N; ++j)
    {
        // 각 열을 저장할 벡터
        vector<int> column(N);
        for (int i = 0; i < N; i++)
        {
            column[i] = board[i][j];
        }
        if (Canpass(column))
        {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}