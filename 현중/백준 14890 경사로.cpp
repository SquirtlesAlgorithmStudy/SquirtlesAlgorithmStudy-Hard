// 백준 14890 경사로

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L; // 칸의 갯수,

vector<vector<int>> board;

bool Canpass(vector<int> &line)
{
    // 0. 사용 여부 확인
    vector<bool> used(N, false); //

        for (int i = 0; i < N - 1; ++i)
    {
        // 1. 높이가 같을 때
        if (line[i] == line[i + 1])
        {
            continue;
        }

        // 2. 만약 차이가 1보다 크면 설치 불가능
        if (abs(line[i] - line[i + 1]) > 1)
            return false;

        // 3. 내려갈 때
        if (line[i] > line[i + 1])
        {
            // 3.1 경사로가 설치 가능한지 확인
            for (int j = i + 1; j <= i + L; ++j)
            {
                if (j >= N || line[j] != line[i + 1] || used[j])
                    return false; // 1. 범위밖이거나 2. 높이가 같지 않거나 3. 이미 쓰인곳은 무시
                used[j] = true;
            }
        }
        // 4. 올라갈 때
        else
        {
            for (int j = i; j > i - L; --j)
            {
                if (j < 0 || line[j] != line[i] || used[j])
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
    board.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    int result = 0;

    // 행 확인
    for (int i = 0; i < N; ++i)
    {
        if (Canpass(board[i]))
            result++;
    }

    // 열 확인
    for (int j = 0; j < N; ++j)
    {
        vector<int> column(N); // 각 열의 데이터를 임시로 저장할 벡터 선언
        for (int i = 0; i < N; ++i)
        {
            column[i] = board[i][j]; // 각 행에서 해당 열의 값을 벡터에 저장
        }
        if (Canpass(column))
            result++; // 그 열에 대해 경사로 설치가 가능한지 확인
    }

    cout << result << endl;

    return 0;
}