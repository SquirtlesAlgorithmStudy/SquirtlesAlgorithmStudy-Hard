// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue> 
#include <functional> // greater
#include <algorithm> // sort()

using namespace std;

struct ascending_for_pq{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second; // second를 기준으로 내림차순
    }
}; //pq는 struct의 연산자 오버로딩으로 우선순위 결정. 

struct descending_for_pq{
    bool operator()(pair<int,int> a, pair<int, int> b){
        return a.second > b.second; // second를 기준으로 오름차순
    }
}; // pq는 struct의 연산자 오버로딩으로 우선순위 결정.

bool ascending_for_sort(pair<int,int> a, pair<int,int> b){
    return a.second < b.second; // second를 기준으로 오름차순
}

bool descending_for_sort(pair<int, int> a, pair<int, int> b){
    return a.second > b.second; // second를 기준으로 내림차순
}

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, ascending_for_pq> pq;
    priority_queue<pair<int, int>, vector<pair<int,int>>, descending_for_pq> pq_desc;
    pq.push({1,5});
    pq.push({2,4});
    pq.push({3,3});

    pq_desc.push({1,5});
    pq_desc.push({2,4});
    pq_desc.push({3,3});

    while(!pq.empty()){
        cout << pq.top().first << "," << pq.top().second << " ";
        pq.pop();
    }
    cout << endl;

    while(!pq_desc.empty()){
        cout << pq_desc.top().first << "," << pq_desc.top().second << " ";
        pq_desc.pop();
    }
    cout << endl;

    vector<pair<int, int>> v1;

    v1.push_back({1,5});
    v1.push_back({2,4});
    v1.push_back({3,3});

    sort(v1.begin(), v1.end(), ascending_for_sort);
    for(int i=0; i<v1.size(); i++){
        cout << v1[i].first << "," << v1[i].second << " ";
    }
    cout << endl;

    sort(v1.begin(), v1.end(), descending_for_sort);
    for(int i=0; i<v1.size(); i++){
        cout << v1[i].first << "," << v1[i].second << " ";
    }
    cout << endl;


}