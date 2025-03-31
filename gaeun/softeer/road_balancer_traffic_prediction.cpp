// 이 방식은 왜 틀릴까? 

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll N, K;
vector<ll> result;

int main(){
    cin >> N >> K;
    result.resize(N+1);
    result[1] = K;

    for(int i=1; i<=N; i++){
        int r; // max 50만 -> int 가능
        cin >> r;

        if(r > 0){
            vector<int> p;
            for(int j=0; j<r; j++){
                int pi; // max 10만 -> int 가능
                cin >> pi;
                p.push_back(pi);
            }
            ll req = result[i];
            ll quo = req/r;
            ll rem = req%r;
            if(quo > 0){
                for(int j=0; j<r; j++){
                    result[p[j]] += quo; 
                }
            }            
            for(int j=0; j<rem; j++){
                result[p[j]] += 1;
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout << result[i] << " ";
    }
    cout << endl; 
}