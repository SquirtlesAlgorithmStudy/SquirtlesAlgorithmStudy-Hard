#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

ll N,K;
vector<ll> A;
ll answer = -1;

void findSec(ll n){
	double sec = log2((double)(K+1)/(n+1));
    if(sec == 0){
        answer = 0;
    }
    else if(fabs(sec - int(sec)) < 1e-9){
			if(answer == -1) answer = (ll)sec;
			else answer = min(answer, (ll)sec);
    }
}

int main() {
	cin >> N >> K;
	for(int i=0; i<N; i++){
		ll a;
		cin >> a;
		A.push_back(a);
	}

	for(int i=0; i<N; i++){
		findSec(A[i]);
	}
	
	cout << answer << "\n";
}