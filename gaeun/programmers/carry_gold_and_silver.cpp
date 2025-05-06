#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool checkCarry(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long mid){
    long long totGold=0, totSilver=0, totWeight=0;

    for(long long i=0; i<g.size(); i++){
        long long num = mid / (2*t[i]);
        if(mid % (2*t[i]) >= t[i]) num++;

        long long carryNum = num;
        long long carryWeight = num * w[i];

        totGold += min((long long)g[i], carryWeight);
        totSilver += min((long long)s[i], carryWeight);
        totWeight += min((long long)(g[i] + s[i]), carryWeight);
    }

    if(totGold >= a && totSilver >= b && totWeight >= a+b) return true;
    else return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long l = 0;
    long long r = 4*pow(10,14) + pow(10,15);

    while(l<=r){
        long long mid = (l+r)/2;
        if(checkCarry(a,b,g,s,w,t, mid)){
            answer = min(answer, mid);
            r = mid - 1;
        } 
        else l = mid + 1;
    }
    return answer;
}