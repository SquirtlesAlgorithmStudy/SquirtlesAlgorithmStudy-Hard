#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> W;
vector<int> compare;
int result=0;

int main(){
    cin >> N >> M;
    compare.resize(N, 0);
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        W.push_back(n);
    }
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;

        if(W[a-1] < W[b-1]) compare[a-1]++;
        else if(W[a-1] > W[b-1]) compare[b-1]++;
        else {compare[a-1]++; compare[b-1]++;}
    }

    for(int n:compare) if(n==0) result++;

    cout << result << endl;
}