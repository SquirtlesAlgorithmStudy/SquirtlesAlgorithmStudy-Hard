#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
vector<int> arr;

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }

    set<int> s(arr.begin(), arr.end()); // remove duplicated elements and sort in ascending order
    vector<int> sortedArr(s.begin(), s.end());

    for(int i=0; i<N; i++){
        int answer;
        answer = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin();
        cout << answer << " ";
    }
    cout << endl;

}