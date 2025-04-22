#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
vector<string> wordList;
set<char> alphabetSet;
vector<char> alphabetVec;
set<char> selected;
int antaticaNum = 0;
int answer = 0;

bool isReadable(string str){
    for(int i=0; i<str.size(); i++){
        if(selected.find(str[i]) == selected.end()) return false;
    }
    return true;
}

void comb(int s_i, int depth){
    if(depth == K-5 || depth == alphabetVec.size()){
        int cnt = antaticaNum;
        
        // cout << "curr selected: ";
        // for(char c: selected) cout << c << " ";
        // cout << "\n";
        for(string str:wordList){
            if(isReadable(str)) cnt++;

            // cout << "curr str: " << str << ", cnt: " << cnt << "\n";
        }
        // cout << "\n";
        answer = max(answer, cnt);
    }

    else{
        for(int i=s_i; i<alphabetVec.size(); i++){
            selected.insert(alphabetVec[i]);
            comb(i+1, depth+1);
            selected.erase(alphabetVec[i]);
        }
    }    
}

int main(){
    cin >> N >> K;

    if(K<5){
        cout << 0 << "\n";
        return 0;
    }

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        if(str == "antatica"){
            antaticaNum++;
            answer = antaticaNum;
            continue;
        }
        
        string onlyMiddleStr;
        for(int j=4; j<str.size()-4; j++){
            if(str[j]!='a' && str[j]!='n' && str[j]!='t' && str[j]!='i' && str[j]!='c'){
                onlyMiddleStr += str[j];
                alphabetSet.insert(str[j]);
            }
        }
        wordList.push_back(onlyMiddleStr);
    }

    for(char c:alphabetSet){
        alphabetVec.push_back(c);
    }

    comb(0,0);

    cout << answer << "\n";
}