#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> loc;

int main(){
    cin >> N >> M >> K;
    for(int i=0; i<K; i++){
        int k;
        cin >> k;
        loc.push_back(k);
    }

    // parametric search: set mid as the minimum distance and check M judges can be located
    int l = 0;
    int r = N;
    string answer = "";
    while(l<=r){
        int mid = (l+r)/2;
        
        // 가장 큰 수: 맨 앞자리 앉히고 시작
        int set = 0;
        string current = "1";
        int cnt = 1;
        for(int i=1; i<K; i++){
            if(loc[i]-loc[set] >= mid){
                if(cnt < M) current += "1"; // 앉힐 인원 남아있는 경우
                else current += "0"; // 이미 M명 다 앉혔음                
                set = i;
                cnt++;
            }
            else{
                current += "0";
            }
        }

        // min dist를 줄여서 다시 확인
        if(cnt < M){
            r = mid - 1;
        }

        // min distance를 키워서 다시 확인
        else{
            l = mid +1;
            answer = current;
        }
    }

    cout << answer << endl;
}