#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> homeworkList;

bool compare(pair<int,int> a, pair<int,int> b){
    if(b.second != a.second) return a.second > b.second;
    return a.first > b.first;
}

int main(){
    cin >> N;

    int max_d = 0;
    for(int i=0; i<N; i++){
        int d, w;
        cin >> d >> w;
        max_d = max(max_d, d);
        homeworkList.push_back({d,w});
    }

    sort(homeworkList.begin(), homeworkList.end(), compare);

    vector<bool> visited(N,0);
    int answer = 0;
    for(int day=max_d; day>0; day--){
        for(int i=0; i<homeworkList.size(); i++){
            if(visited[i]) continue;
            if(homeworkList[i].first >= day){
                answer += homeworkList[i].second;
                visited[i] = 1;
                break;
            }
        }
    }

    cout << answer << "\n";

}