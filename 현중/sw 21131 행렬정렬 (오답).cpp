// sw 21131 행렬정렬 (greedy) (오답)

#include <iostream>
#include <vector>

using namespace std;

// 1. 정렬 행렬 생성 createTargetMatrix<0,0,0> 0-> target<1,2,3>
vector<vector<int>> createTargetMatrix(int N)
{
    vector<vector<int>> target(N, vector<int>(N)); // target(3, vector<int>(3));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            target[i][j] = i * N + (j + 1);
        }
    }
    return target;
}

// 2. 행렬 전치 함수

void transpose(vector<vector<int>> &matrix, int x)
{
    for (int i = 0; i < x; ++i)
    { // 행을 순회
        for (int j = i + 1; j < x; ++j)
        { // 대각선 위쪽만 순회
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// 3. 정렬 행렬 만드는데 필요한 최소 전치 수 계산 / 행렬을 확인하면서 차이를 발견하면 전치 / 전치할 행렬벡터 A -> target 행렬벡터 B / 행렬크기N
int minimumTransposition(vector<vector<int>> &A, vector<vector<int>> &B, int N)
{
    int count = 0;

    for (int x = N; x > 0; --x)
    { // greedy하게 확인
        bool needsTransposition = false;
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < x; ++j)
            {
                if (A[i][j] != B[i][j])
                {
                    needsTransposition = true;
                    break;
                }
            }
            if (needsTransposition == true)
                break; // 중복연산방지 -> 차이가 발견되면 바로 이중반복문 중단
        }
        if (needsTransposition)
        {
            transpose(A, x); // N*N 중 x*x 부분행렬A  전치
            count++;         // 전치 횟수 증가
        }
    }
    return count;
}

// 4. main
int main()
{
    int testcase;
    cin >> testcase;

    while (testcase--)
    { // T가 0이 될때까지 반복
        int N;
        cin >> N;

        vector<vector<int>> A(N, vector<int>(N)); // N*N크기 2차원 벡터 A, 행렬내용 입력받고
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> A[i][j];
            }
        }

        // 목표 행렬을 생성하고
        vector<vector<int>> target = createTargetMatrix(N);

        // A 와 target을 비교하여, 필요할때마다 전치 -> 최소 전치 횟수 구해
        int result = minimumTransposition(A, target, N);

        cout << result << endl;
    }

    return 0;
}