#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> req;
long long total;
long long reqMax = 0;

bool check(int val){
    long long reqSum = 0;
    for(int i=0; i<N; i++){
        if(req[i] > val) reqSum += val;
        else reqSum += req[i];
    }
    if(reqSum <= total) return true;
    else return false;
}

long long parSearch(){
    long long low = 0;
    long long high = reqMax;
    long long mid;
    long long answer = 0;
    while(low <= high){
        mid = low + (high - low)/2; 
        if(check(mid)){
            answer = mid;
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return answer;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        req.push_back(n);
    }
    cin >> total;

    long long sum = 0;
    for(int i=0; i<N; i++){
        sum += req[i];
        if(req[i] > reqMax) reqMax = req[i];
    }
    if(sum > total){
        cout << parSearch() << endl;
    }
    else{
        cout << reqMax << endl;
    }
}