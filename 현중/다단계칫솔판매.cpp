// 프로그래머스 다단계 칫솔 판매

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> mres;
map<string, string> mref;
vector<int> answer;

void distribute(string seller, int money) {
    if(seller=="-") return;
    int part = money*0.1;
    mres[seller]+=money-part;
    if(part) distribute(mref[seller], part);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    for(int i=0;i<enroll.size();i++){
        mres[enroll[i]]=0;
        mref[enroll[i]]=referral[i];
    }
    
    for(int i=0;i<seller.size();i++){
        distribute(seller[i], amount[i]*100);
    }
        
    for(int i=0;i<mres.size();i++){
        answer.push_back(mres[enroll[i]]);
    } 
    return answer;
}


