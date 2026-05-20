#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<string, int> m;
vector<pair<string, int>> v;

bool compare(pair<string, int> p1, pair<string, int> p2){
    if(p1.second != p2.second) return p1.second > p2.second;
    else return p1.first < p2.first;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        m[s]++;
    }

    for(auto ele : m){
        v.push_back({ele.first, ele.second});
    }

    sort(v.begin(), v.end(), compare);

    cout << v[0].first << endl;
}