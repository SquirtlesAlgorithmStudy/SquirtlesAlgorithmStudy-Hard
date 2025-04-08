#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
vector<int> N, K;
vector<string> str;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    for(int t=0; t<T; t++){
        int n, k;
        cin >> n >> k;
        N.push_back(n); K.push_back(k);

        string s;
        cin >> s;
        str.push_back(s);
    }

    for(int t=0; t<T; t++){
        string s;
        int cnt = 0;
        vector<int> cases;
        for(int i=0; i<(N[t]/4); i++){
            for(int j=0; j<N[t]; j++){
                int idx = (j-i+N[t]) % N[t];
                s+=str[t][idx];
                cnt++;
                if(cnt == N[t]/4){
                    int num = stoi(s,nullptr,16);
                    if(find(cases.begin(), cases.end(), num) == cases.end()) cases.push_back(num);
                    s = "";
                    cnt = 0;
                }
            }
        }
        sort(cases.begin(), cases.end(), greater<int>());
        cout << "#" << t+1 << " " << cases[K[t]-1] << "\n";
    }


}