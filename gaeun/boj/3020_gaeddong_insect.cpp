#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, H;
int jongyouseok[5000001] = {0,};
int seoksun[5000001] = {0,};
int prefix_jongyouseok[5000001] = {0,};
int prefix_seoksun[5000001] = {0,};


int main(){
    cin >> N >> H;
    for(int i=0; i<N; i++){
        int h;
        cin >> h;

        if(i%2 == 0){
            jongyouseok[h] += 1;
        }
        else seoksun[H-h+1] += 1;
    }

    int sum_j = 0, sum_s = 0;
    for(int i=1; i<=H; i++){
        int j=H-i+1;

        prefix_seoksun[i] = seoksun[i] + sum_s;
        sum_s = prefix_seoksun[i];

        prefix_jongyouseok[j] = jongyouseok[j] + sum_j;
        sum_j = prefix_jongyouseok[j];
    }

    int cnt = 0;
    int ans = INT_MAX;
    for(int i=1; i<=H; i++){
        if(ans == prefix_jongyouseok[i]+prefix_seoksun[i]) cnt++;
        else if(ans > prefix_jongyouseok[i]+prefix_seoksun[i]){
            ans = prefix_jongyouseok[i]+prefix_seoksun[i];
            cnt = 1;
        }
    }

    cout << ans << " " << cnt << "\n";
}
