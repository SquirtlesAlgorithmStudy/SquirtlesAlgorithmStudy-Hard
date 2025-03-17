#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int arr[100000];
int leftDP[100000]; // DP stores local max
int rightDP[100000];
int leftBest[100000]; // Best stores global max
int rightBest[100000];
int result = INT_MIN;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int m;
        cin >> m;
        arr[i] = m;
    }

    leftDP[0] = arr[0];
    leftBest[0] = leftDP[0];
    
    rightDP[N-1] = arr[N-1];
    rightBest[N-1] = rightDP[N-1];

    // update local max and global max for the first cuisine
    for(int i=1; i<N-2; i++){
        leftDP[i] = max(arr[i], leftDP[i-1]+arr[i]);
        leftBest[i] = max(leftDP[i], leftBest[i-1]);
    }

    // update local max and global max for the second cuisine
    for(int i=N-2; i>1; i--){
        rightDP[i] = max(arr[i], rightDP[i+1]+arr[i]);
        rightBest[i] = max(rightDP[i], rightBest[i+1]);
    }

    // get the answer
    for(int i=0; i<N-2; i++){
        result = max(result, leftBest[i] + rightBest[i+2]);
    }

    cout << result << endl;
}