#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll N,K;
vector<ll> A;
int answer = -1;

ll getLeftValue(int mid){
	if(mid==0) return 1;

	ll value = 1;
	for(int i=0; i<mid; i++){
		value *= 2;
	}
	return value;
}

void findSec(ll n){
	int l = 0; int r = 30;
	int mid = (l+r)/2;
	double rightValue = (double)(K+1)/(n+1);

	while(l<=r){
		mid = (l+r)/2;
		ll leftValue = getLeftValue(mid);

		if(leftValue == rightValue){
			if(answer == -1) answer = mid;
			else answer = min(answer, mid);
		} 

		if(leftValue < rightValue) l = mid+1;
		else r = mid-1;
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