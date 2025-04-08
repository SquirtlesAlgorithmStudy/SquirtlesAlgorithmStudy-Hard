#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> lessons;

int main(){
    cin >> N >> M;

    int total = 0;
    int maxLesson = 0;
    for(int i=0; i<N; i++){
        int l;
        cin >> l;
        lessons.push_back(l);
        total += l;
        maxLesson = max(maxLesson, lessons[i]);
    }
    
    int l = maxLesson;
    int r = total;
    
    while(l<=r){
        int sum = 0;
        int cnt = 0;

        int mid = (l+r)/2;

        for(int i=0; i<N; i++){
            if(sum + lessons[i] > mid){
                sum = 0;
                cnt++;
            }
            sum += lessons[i];
        }
        if(sum != 0) cnt++; // 마지막 블루레이

        if(cnt > M) // 길이 늘려야됨
        {
            l = mid + 1;
        }
        else // cnt < M이라면 길이 줄여야하고, cnt == M이어도 최소를 찾기 위해 줄여보자.
        {   
            r = mid - 1;
        }
    }

    cout << l << "\n"; // 조건을 만족시키는 최소는 l에 저장되어있다. 

}