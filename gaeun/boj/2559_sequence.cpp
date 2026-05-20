#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> A, preSum, sumK;

int main(){
    cin >> N >> K;
    A.resize(N+1);
    preSum.resize(N+1);
    sumK.resize(N+1);

    for(int i=1; i<=N; i++){
        cin >> A[i];
    }

    for(int i=1; i<=N; i++){
        preSum[i] = preSum[i-1] + A[i];
    }

    for(int i=K; i<=N; i++){
        sumK[i] = preSum[i] - preSum[i-K];
    }

    sort(sumK.begin()+K, sumK.end(), greater<int>());

    cout << sumK[K] << endl;
}