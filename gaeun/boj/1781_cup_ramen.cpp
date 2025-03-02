#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional> // greater
using namespace std;

int N;
vector<pair<int, int>> contents; // first: deadline, second: 컵라면 개수
priority_queue<int, vector<int>, greater<int>> pq; 
int result=0;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int deadline, cupramen;
        cin >> deadline >> cupramen;

        contents.push_back({deadline, cupramen});
    }
    
    sort(contents.begin(), contents.end()); // deadline이 짧은것부터 오름차순 정렬

    for(int i=0; i<N; i++){
        pq.push(contents[i].second);
        if(contents[i].first < pq.size()) pq.pop();
    }

    while(!pq.empty()){
        result += pq.top();
        pq.pop();
    }

    cout << result << endl;
}