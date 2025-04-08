#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> req;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        req.push_back(n);
    }
    cin >> M;

    int l = 0; // M은 N 이상인 수임. 만약 N=4일 때, 총 예산액 M도 4일 수 있어. 그러니 l을 4보다 큰 값으로 하면 틀리겠지?
    int r = *max_element(req.begin(), req.end());
    ans.resize(N);

    while(l<=r){
        int mid = (l + r)/2;
        int sum = 0;
        for(int i=0; i<N; i++){
            if(req[i] <= mid){
                sum += req[i];
                ans[i] = req[i];
            } 
            else{
                sum += mid;
                ans[i] = mid;
            } 
        }
        if(sum <= M){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    for(int i=0; i<N; i++){
        if(ans[i] > r) ans[i] = r;
    }

    cout << *max_element(ans.begin(), ans.end()) << "\n";
}