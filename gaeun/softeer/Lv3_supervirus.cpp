#include <iostream>
using namespace std;

using ll = long long;
#define MOD 1000000007

ll K, P, N;
ll result = 1;
ll base, exp;

// int main(){
//     cin >> K >> P >> N;
//     base = P;
//     exp = 10*N;
//     while(exp > 0){
//         if(exp % 2 != 0){
//             result = (result * base) % MOD;
//         }
//         base = (base * base) % MOD;
//         exp /= 2;
//     }
//     cout << K * result % MOD << endl;
// }

int main(){
    cin >> K >> P >> N;
    base = P;
    exp = 10*N;
    while(exp > 0){
        if(exp % 2 != 0){
            result = (result * base) % MOD;
            exp -= 1;
        }
        else{
            base = (base * base) % MOD;
            exp /= 2;
        }        
    }
    cout << K * result % MOD << endl;
}