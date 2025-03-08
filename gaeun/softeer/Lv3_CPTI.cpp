#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <algorithm> // count()
using namespace std;

int N, M;
vector<int> cpti;
unordered_map<int, int> cptiFreq;

// O(N M^2)인데 왜 TLE뜨는지 모르겠음
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        // get each cpti in string
        string s;
        cin >> s;

        // store each cpti in binary. M <=30 -> store it in int(32bit)
        int bits = stoi(s, nullptr, 2);
        
        cptiFreq[bits]++;
        cpti.push_back(bits);
    }

    int answer = 0;
    for(int i=0; i<N; i++){
        int key = cpti[i];

        // same bit
        answer += cptiFreq[key] - 1; // -1 for itself

        // one bit difference
        for(int bit=0; bit<M; bit++){
            int fliped = key ^ (1 << bit);
            answer += cptiFreq[fliped];
        }

        // two bit difference
        for(int bit1=0; bit1<M; bit1++){
            for(int bit2=0; bit2<bit1; bit2++){
                int fliped = (key ^ (1 << bit1)) ^ (1 << bit2);
                answer += cptiFreq[fliped];
            }
        }

        cptiFreq[key]--; // prevent duplication
    }
    cout << answer << endl;
}

// TLE (O(N^2 M))
// int main(){
//     cin >> N >> M;
//     for(int i=0; i<N; i++){
//         // get each cpti in string
//         string s;
//         cin >> s;

//         // store each cpti in binary
//         int bits = stoi(s, nullptr, 2);
//         cpti.push_back(bits);
//     }

//     int answer=0;
//     for(int i=0; i<N; i++){
//         for(int j=i+1; j<N; j++){
//             string familiar = bitset<30>(~(cpti[i]^cpti[j])).to_string().substr(30-M);
//             int zeros = count(familiar.begin(), familiar.end(), '0');
//             if(zeros <= 2) answer++;
//         }
//     }

//     cout << answer << endl;
// }