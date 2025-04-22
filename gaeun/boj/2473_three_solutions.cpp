#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
vector<ll> solutionList;
ll answerSum = (ll)3*1000000000;
vector<int> answer(3);

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        solutionList.push_back(n);
    }
    sort(solutionList.begin(), solutionList.end());

    for(int i=0; i<N-2; i++){
        int left = i+1;
        int right = N-1;

        while(left < right){
            ll sum = solutionList[i] + solutionList[left] + solutionList[right];

            if(abs(sum) < abs(answerSum)){
                answer[0] = solutionList[i];
                answer[1] = solutionList[left];
                answer[2] = solutionList[right];
                answerSum = sum;

                // cout << "sum: " << sum << ", made of "; 
                // cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
            }

            if(sum < 0) left++;
            else right--;
        }
    }
    cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
}