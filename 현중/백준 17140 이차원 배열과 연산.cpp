// 백준 17140 이차원 배열과 연산

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int r, c, k;
int arr[101][101];
int rowSize = 3, colSize = 3;

void R_operation()
{
    // 목표는 가장 긴 열을 찾고, 짧은 부분들은 다 0
    int maxColSize = 0;
    // 모든행 숫자, 갯수 세
    // 행 정렬(map의 내용을 vector로 변환)
    // 정렬된 값을 배열에 다시 넣어
    // 남은 부분은 0으로 채워
    for (int i = 0; i < rowSize; i++)
    {
        map<int, int> countmap; // map(각 행의 숫자, 숫자의 등장 횟수)
        for (int j = 0; j < colSize; j++)
        {
            if (arr[i][j] != 0) // 각 행의 열을 탐색
            {
                countmap[arr[i][j]]++; // 숫자가 0이 아닌 경우만 count
            }
        }

        // 숫자 등장 횟수에 따라 정렬 countmap()
        vector<pair<int, int>> countVec(countmap.begin(), countmap.end()); // map의 내용을 vector<int,int>로 변환

        sort(countVec.begin(), countVec.end(), [](pair<int, int> a, pair<int, int> b)
             {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second; });

        // 정렬된 값 배열에 넣기
        int idx = 0;
        for (auto r : countVec)
        {
            arr[i][idx++] = r.first;
            arr[i][idx++] = r.second;
            if (idx >= 100)
                break;
        }

        for (int j = idx; j < 100; ++j)
        {
            arr[i][j] = 0;
        }
        maxColSize = max(maxColSize, idx);
    }
    colSize = maxColSize;
}

void C_operation()
{
    // 목표는 가장 긴 열을 찾고, 짧은 부분들은 다 0
    // 모든행 숫자, 갯수 세
    // 행 정렬(map의 내용을 vector로 변환)
    // 정렬된 값을 배열에 다시 넣어
    // 남은 부분은 0으로 채워
    int maxRowSize = 0;
    for (int j = 0; j < colSize; ++j)
    {
        map<int, int> countmap; // <숫자 갯수>
        for (int i = 0; i < rowSize; i++)
        {
            if (arr[i][j] != 0)
            { // 0이 아닌 경우만 세야
                countmap[arr[i][j]]++;
            }
        }

        // 숫자 등장 횟수에 따라 정렬 countmap()
        vector<pair<int, int>> countVec(countmap.begin(), countmap.end());
        sort(countVec.begin(), countVec.end(), [](pair<int, int> a, pair<int, int> b)
             {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second; });

        int idx = 0;
        for (auto r : countVec)
        {
            arr[idx++][j] = r.first;
            arr[idx++][j] = r.second;
            if (idx >= 100)
                break;
        }

        for (int i = idx; i < 100; ++i)
        {
            arr[i][j] = 0;
        }
        maxRowSize = max(maxRowSize, idx);
    }
    rowSize = maxRowSize;
}

int main()
{
    cin >> r >> c >> k;
    r--;
    c--;

    // 초기 배열 입력
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int time = 0;
    while (arr[r][c] != k)
    {
        if (time > 100)
        {
            cout << -1 << endl;
            return 0;
        }

        if (rowSize >= colSize)
        {
            R_operation();
        }
        else
        {
            C_operation();
        }
        time++;
    }

    cout << time << endl;
    return 0;
}