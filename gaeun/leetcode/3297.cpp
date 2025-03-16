#include <iostream>
#include <unordered_map>
using namespace std;

// typedef long long ll; // old ver.
using ll = long long;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> umap1, umap2;
        for(char c='a'; c<='z'; c++){
            umap1[c] = 0;
        } // generate a:0, b:0, .., z:0
        for(int i=0; i<word2.size(); i++){
            umap2[word2[i]]++;
        }

        ll numNeedToBeMached = word2.size();
        ll cnt = 0;
        ll lptr = -1;
        for(ll rptr=0; rptr<word1.size(); rptr++){
            char currChar = word1[rptr];
            umap1[currChar]++;
            if(umap1[currChar] <= umap2[currChar]){
                numNeedToBeMached--;
            }
            while(numNeedToBeMached == 0){
                cnt += word1.size() - rptr;
                lptr++;
                currChar = word1[lptr];
                umap1[currChar]--;
                if(umap1[currChar] < umap2[currChar]){
                    numNeedToBeMached++;
                }
            }

        }
        return cnt;
    }
};

int main(){
    Solution sol;
    string w1 = "abcabc";
    string w2 = "abc";
    cout << sol.validSubstringCount(w1, w2) << endl;

}