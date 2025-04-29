#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

long long strToPos(string str){
    long long pos = 0;
    for(int i=0; i<str.size(); i++){
        pos += (str[i] - 'a' + 1) * pow(26,str.size()-1-i);
    }
    return pos;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    
    // 삭제된 문자열 중 n번째보다 앞선 주문이 몇개인지 카운팅
    sort(bans.begin(), bans.end(), compare);
    for(int i=0; i<bans.size(); i++){
        if(strToPos(bans[i])<=n) n++;
    }
    
    // 1~11글자 각각이 갖는 주문 수
    long long numEachDigit[12];
    numEachDigit[1] = 26;
    for(int i=2; i<=11; i++){
        numEachDigit[i] = numEachDigit[i-1]*26;
    }
    
    // n번째 주문이 갖는 글자 수
    int length = 1;
    for(; length<=11; length++){
        if(numEachDigit[length] >= n) break;
    }
    
    // 26진법으로 n을 문자열로 변환
    string str;
    for(int i=0; i<length; i++){
        n--;
        str += (char)('a' + n%26);
        n = n/26;
    }
    
    // reverse
    for(int i=str.size()-1; i>=0; i--){
        answer += str[i];
    }
        
    return answer;
}