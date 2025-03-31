#include <iostream>
#include <vector>
using namespace std;

int N;
int B,C;
vector<int> arr;

int main(){
    cin >> N;

    long long director = N;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    cin >> B >> C;

    for(int i=0; i<N; i++){
        arr[i] = arr[i] - B;
        if(arr[i] < 0) arr[i] = 0;
    }

    for(int i=0; i<N; i++){
        int m = arr[i] / C;
        int r = arr[i] % C;
        
        (r == 0) ? director += m : director += m+1;
    }

    cout << director << endl;
}