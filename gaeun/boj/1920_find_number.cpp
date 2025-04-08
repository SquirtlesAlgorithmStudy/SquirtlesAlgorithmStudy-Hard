#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
vector<int> arr;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }

    sort(arr.begin(), arr.end());

    cin >> M;
    for(int i=0; i<M; i++){
        int m;
        cin >> m;
        bool flag = binary_search(arr.begin(), arr.end(), m);
        if(flag) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}