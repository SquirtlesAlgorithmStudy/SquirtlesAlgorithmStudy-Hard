#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    string str110 = "110";
    for(string str: s){
        // extract all the 110s
        string afterExtract = "";
        int cnt = 0;
        for(char c:str){
            afterExtract += c;

            if(afterExtract.size() >= 3){
                if(afterExtract[afterExtract.size()-3] == '1' && afterExtract[afterExtract.size()-2] == '1' && afterExtract[afterExtract.size()-1] == '0'){
                    cnt++;
                    afterExtract.erase(afterExtract.end()-3, afterExtract.end());
                }
            }
        }

        // find where to put
        int zeroPos = -1;
        for(int i=0; i<afterExtract.size(); i++){
            if(afterExtract[i] == '0') zeroPos = i; // find the latest zero's position
        }
        cout << "string after extraction: " << afterExtract << "\n";
        cout << "zeroPos: " << zeroPos << "\n";

        // put 110s
        string result = "";
        if(zeroPos != -1){
            result += afterExtract.substr(0, zeroPos+1);
            while(cnt--) result += "110";
            result += afterExtract.substr(zeroPos+1);
        }
        else{
            while(cnt--) result += "110";
            result += afterExtract;
        }
        
        answer.push_back(result);
    }
    return answer;
}