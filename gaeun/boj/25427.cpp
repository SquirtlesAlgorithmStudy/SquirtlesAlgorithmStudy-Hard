#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
string str;

int main(){
    cin >> N;
    cin >> str;

    ll d=0, dk=0, dks=0, dksh=0;

    for(int i=0; i<N; i++){
        if(str[i] == 'D') d++;
        if(str[i] == 'K') dk += d;
        if(str[i] == 'S') dks += dk;
        if(str[i] == 'H') dksh += dks;
    }

    cout << dksh << endl;
}