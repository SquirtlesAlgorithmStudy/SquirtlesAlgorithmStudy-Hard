#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N;
int T[16];
int P[16];
vector<vector<pair<int, int>>> cases;
int result = 0;

int main(){
    cin >> N;
    cases.resize(N);
    for(int i=0; i<N; i++){
        cin >> T[i] >> P[i];
    }

    int idx = 0;
    while(idx < N){
        if(idx-1<0 || cases[idx-1].empty()){
            if(T[idx]+idx+1-1 <= N) cases[idx].push_back({P[idx], T[idx]+idx+1-1});
            result = max(result, P[idx]);
        }
        else{
            for(int k=0; k<cases[idx-1].size(); k++){
                // 이전 선택 유지 or 누적
                if(cases[idx-1][k].second < idx+1){ 
                    if(find(cases[idx].begin(), cases[idx].end(), make_pair(cases[idx-1][k].first, cases[idx-1][k].second)) == cases[idx].end()){
                        if(cases[idx-1][k].second <= N){
                            cases[idx].push_back({cases[idx-1][k].first, cases[idx-1][k].second});
                            result = max(result, cases[idx-1][k].first);
                        }
                    }
                    if(find(cases[idx].begin(), cases[idx].end(), make_pair(cases[idx-1][k].first+P[idx], T[idx]+idx+1-1)) == cases[idx].end()){
                        if(T[idx]+idx+1-1 <= N){
                            cases[idx].push_back({cases[idx-1][k].first+P[idx], T[idx]+idx+1-1});
                            result = max(result, cases[idx-1][k].first+P[idx]);
                        }
                    }
                }
    
                // 이전 선택 유지 or 이번걸 선택하거나
                else{
                    if(find(cases[idx].begin(), cases[idx].end(), make_pair(cases[idx-1][k].first, cases[idx-1][k].second)) == cases[idx].end()){
                        if(cases[idx-1][k].second <= N){
                            cases[idx].push_back({cases[idx-1][k].first, cases[idx-1][k].second});
                            result = max(result, cases[idx-1][k].first);
                        }
                    }
                    if(find(cases[idx].begin(), cases[idx].end(), make_pair(P[idx], T[idx]+idx+1-1)) == cases[idx].end()){
                        if(T[idx]+idx+1-1 <= N){
                            cases[idx].push_back({P[idx], T[idx]+idx+1-1});
                            result = max(result, P[idx]);
                        }
                    }
                }
            }
        }
        
        idx++;
    }

    cout << result << endl;
}