#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> wordMask;
int checked = 0;
int answer = 0;

void comb(int start, int depth){
    if(depth == K-5){
        int cnt = 0;
        for(int i=0; i<wordMask.size(); i++){
            if((wordMask[i] & checked) == wordMask[i]) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }

    for(int i=start; i<26; i++){
        if(checked & (1 << i)) continue;
        checked |= 1 << i;
        comb(i+1, depth+1);
        checked &= ~(1 << i);
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

        int num=0;
        for(int j=0; j<str.size(); j++){
            num |= 1 << (str[j] - 'a');
        }
        wordMask.push_back(num);
    }

    checked |= 1 << ('a' - 'a');
    checked |= 1 << ('n' - 'a');
    checked |= 1 << ('t' - 'a');
    checked |= 1 << ('i' - 'a');
    checked |= 1 << ('c' - 'a');

    comb(0,0);

    cout << answer << "\n";

}