#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> v;

int main(){
    v.push_back(3);
    v.push_back(3);

    int N;
    cin >> N;
    v.resize(N+1, 6);
    for(int n:v) cout << n << "\n";

    v.assign(N+1, 5);
    for(int n:v) cout << n << "\n";

    cout << "hello";
    
}