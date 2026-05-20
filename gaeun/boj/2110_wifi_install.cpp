#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> home;

bool check(int dist){
    int installed = home[0];
    int cnt = 1;
    for(int i=1; i<N; i++){
        if(home[i] - installed >= dist){
            cnt++;
            installed = home[i];
        }
    }
    if(cnt >= C) return true;
    else return false;
}

int main(){
    cin >> N >> C;
    for(int i=0; i<N; i++){
        int h;
        cin >> h;
        home.push_back(h);
    }
    sort(home.begin(), home.end());

    int l = 1;
    int h = home[N-1]-home[0];
    int answer = h;

    while(l <= h){
        int m = l + (h-l)/2;
        if(check(m)){
            answer = m;
            l = m+1;
        }
        else h = m-1;
    }

    cout << answer << endl;

}