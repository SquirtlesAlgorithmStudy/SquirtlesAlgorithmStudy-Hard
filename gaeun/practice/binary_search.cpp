#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> v={1,2,3,3,3,4,5};
    cout << "upper_bound(v.begin(), v.end(), 3) - v.begin(): " << upper_bound(v.begin(), v.end(), 3) - v.begin() << endl; // 찾으려는 값을 초과하는 값의 idx 반환 -> 5
    cout << "lower_bound(v.begin(), v.end(), 3) - v.begin(): " << lower_bound(v.begin(), v.end(), 3) - v.begin() << endl; // 찾으려는 값보다 크거나 같은 값의 idx 반환 -> 2
}


