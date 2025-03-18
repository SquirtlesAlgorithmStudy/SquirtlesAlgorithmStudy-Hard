#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;
vector<int> even_accum, odd_accum;
int N;
int result=0; // 카드의 값은 모두 양수

int main(){
    cin >> N;

    int even_sum=0;
    int odd_sum=0;
    even_accum.push_back(0);
    odd_accum.push_back(0);
    
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        card.push_back(n);

        if(i%2 == 0){
            even_sum += n;
            even_accum.push_back(even_sum);
        }
    }

    for(int i=N-3; i>0; i=i-2){
        odd_sum += card[i];
        odd_accum.push_back(odd_sum);
    }

    int totalCardNum = N/2;
    int evenNum, oddNum;

    for(int i=0; i<N; i++) // i는 밑장 뺄 위치
    {
        if(i==0) evenNum = 0;
        else evenNum = (i-1)/2 + 1;
        
        if(i%2 == 0) // 정훈이가 밑장 가져감
        {
            oddNum = totalCardNum-evenNum-1;
            result = max(result, even_accum[evenNum]+card[N-1]+odd_accum[oddNum]);
        }
        else // 상대가 밑장
        {
            oddNum = totalCardNum-evenNum;
            result = max(result, even_accum[evenNum]+odd_accum[oddNum]);
        }
    }

    cout << result << endl;

}