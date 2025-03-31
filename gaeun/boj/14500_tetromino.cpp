#include <iostream>

using namespace std;

int grid[500][500];
int N, M;
int sum=0;
int result=0;

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
        }
    }

    // 1. ----
    for(int i=0; i<N; i++){
        for(int j=0; j+3<M; j++){
            sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i][j+3];
            result = max(result, sum);
        }
    }

    // 2. |
    for(int i=0; i+3<N; i++){
        for(int j=0; j<M; j++){
            sum = grid[i][j] + grid[i+1][j] + grid[i+2][j] + grid[i+3][j];
            result = max(result, sum);
        }
    }

    // 3. ㅁ
    for(int i=0; i+1<N; i++){
        for(int j=0; j+1<M; j++){
            sum = grid[i][j] + grid[i][j+1] + grid[i+1][j] + grid[i+1][j+1];
            result = max(result, sum);
        }
    }

    // 4. 
    for(int i=0; i+2<N; i++){
        for(int j=0; j+1<M; j++){
            sum = grid[i][j] + grid[i+1][j] + grid[i+2][j] + grid[i+2][j+1];
            result = max(result, sum);

            sum = grid[i][j] + grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            result = max(result, sum);

            sum = grid[i+2][j] + grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            result = max(result, sum);

            sum = grid[i][j] + grid[i+1][j] + grid[i+2][j] + grid[i][j+1];
            result = max(result, sum);

            sum = grid[i][j] + grid[i+1][j] + grid[i+1][j+1] + grid[i+2][j+1];
            result = max(result, sum);

            sum = grid[i][j+1] + grid[i+1][j+1] + grid[i+1][j] + grid[i+2][j];
            result = max(result, sum);

            sum = grid[i][j] + grid[i+1][j] + grid[i+2][j] + grid[i+1][j+1];
            result = max(result, sum);

            sum = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] + grid[i+1][j];
            result = max(result, sum);
        }
    }

    //  
    for(int i=0; i+1<N; i++){
        for(int j=0; j+2<M; j++){
            sum = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] + grid[i][j+2];
            result = max(result, sum);

            sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j];
            result = max(result, sum);

            sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+2];
            result = max(result, sum);

            sum = grid[i][j] + grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
            result = max(result, sum);

            sum = grid[i+1][j] + grid[i+1][j+1] + grid[i][j+1] + grid[i][j+2];
            result = max(result, sum);

            sum = grid[i][j] + grid[i][j+1] + grid[i+1][j+1] + grid[i+1][j+2];
            result = max(result, sum);

            sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1];
            result = max(result, sum);

            sum = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] + grid[i][j+1];
            result = max(result, sum);
        }
    }
    
    cout << result << endl;
}