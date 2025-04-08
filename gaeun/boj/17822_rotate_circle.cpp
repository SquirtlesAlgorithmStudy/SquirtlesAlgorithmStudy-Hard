#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
vector<vector<int>> circle(55, vector<int>(55));
struct INFO{
    int x, d, k;
};
vector<INFO> rotateInfo;

int main(){
    cin >> N >> M >> T;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            cin >> circle[i][j];
        }
    }
    for(int i=0; i<T; i++){
        INFO tmp;
        cin >> tmp.x >> tmp.d >> tmp.k;
        rotateInfo.push_back(tmp);
    }

    for(int i=0; i<T; i++){
        INFO currentInfo = rotateInfo[i];

        // x 배수인 원판들 모두 d방향으로 k칸씩 회전
        for(int idx=1; idx<=N; idx++){
            if(idx % currentInfo.x == 0){
                if(currentInfo.d == 0) // CW
                {
                    vector<int> tmp = circle[idx];
                    for(int j=0; j<M; j++){
                        circle[idx][(j+currentInfo.k)%M] = tmp[j];
                    }
                    
                }
                else // CCW
                {
                    vector<int> tmp = circle[idx];
                    for(int j=0; j<M; j++){
                        circle[idx][(j-currentInfo.k+M)%M] = tmp[j];
                    }
                }
            }
        }

        // 숫자 처리
        bool flag = 0;
        vector<vector<int>> clear(55, vector<int>(55));
        for(int r=1; r<=N; r++){
            for(int c=0; c<M; c++){
                int nc = (c + 1) % M;

                if((circle[r][c] != 0) && (circle[r][c] == circle[r][nc])){
                    clear[r][c] = 1;
                    clear[r][nc] = 1;
                    flag = 1;
                }
                if((circle[r][c] != 0) && (circle[r][c] == circle[r+1][c])){
                    clear[r][c] = 1;
                    clear[r+1][c] = 1;
                    flag = 1;
                }
            }
        }

        for(int r=1; r<=N; r++){
            for(int c=0; c<M; c++){
                if(clear[r][c] == 1) circle[r][c] = 0;
            }
        }

        if(!flag){
            float sum = 0;
            float cnt = 0;
            for(int r=1; r<=N; r++){
                for(int c=0; c<M; c++){
                    if(circle[r][c] != 0){
                        sum += circle[r][c];
                        cnt++;
                    }
                }
            }

            if(cnt != 0){
                float avg = sum / cnt;
                for(int r=1; r<=N; r++){
                    for(int c=0; c<M; c++){
                        if(circle[r][c] == 0) continue; 

                        if(circle[r][c] < avg) circle[r][c] += 1;
                        else if(circle[r][c] > avg) circle[r][c] -= 1;
                    }
                }
            }
        }
    }

    // calc the final sum
    int sum = 0;
    for(int r=1; r<=N; r++){
        for(int c=0; c<M; c++){
            sum += circle[r][c];
        }
    }

    cout << sum << endl;
}