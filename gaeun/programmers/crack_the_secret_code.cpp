#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int n,m;
vector<int> arr, ans;
vector<vector<int>> q;

bool check(){
    for(int i=0; i<m; i++){
        int cnt=0;
        for(int j=0; j<5; j++){
            if(find(q[i].begin(), q[i].end(), arr[j]) != q[i].end()) cnt++;
        }
        if(cnt != ans[i]) return false;
    }
    return true;
}

void comb(int s_i, int depth){
    if(depth >= 5){
        if(check()) answer ++;
    }
    else{
        for(int i=s_i; i<=n; i++){
            arr.push_back(i);
            comb(i+1, depth+1);
            arr.pop_back();
        }
    }
}