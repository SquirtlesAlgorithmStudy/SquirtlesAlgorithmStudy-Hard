#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // min()
using namespace std;
/*
    ugly number: 2,3,5만을 소인수로 가지는 양수.
*/

// TLE
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         vector<int> uglyNumbers;
//         int i=1;
//         while(1){            
//             int num = i;
//             while(1){
//                 if(num % 2 == 0){
//                     num /= 2;
//                     continue;
//                 } 
//                 else if(num % 3 == 0){
//                     num /= 3;
//                     continue;
//                 } 
//                 else if(num % 5 == 0){
//                     num /= 5;
//                     continue;
//                 } 
                
//                 if(num == 1){
//                     uglyNumbers.push_back(i);
//                     break;
//                 } 
//                 else break;
//             }
//             if(uglyNumbers.size() >= n) break;
//             i++;
//         }
//         return uglyNumbers[n-1];
//     }
// };
    

class Solution {
public:
    int nthUglyNumber(int n) {
        queue<int> x2;
        queue<int> x3;
        queue<int> x5;
        vector<int> uglyNumbers;

        x2.push(1);
        x3.push(1);
        x5.push(1);
        uglyNumbers.push_back(1);

        while(1){
            // terminal condition
            if(uglyNumbers.size() > n) break;

            // find the minimum
            int min = std::min({x2.front()*2, x3.front()*3, x5.front()*5});

            // choose to pop
            if(min == x2.front()*2) x2.pop();
            else if(min == x3.front()*3) x3.pop();
            else if(min == x5.front()*5) x5.pop();

            // min is one of the ugly numbers
            uglyNumbers.push_back(min);

            // push the min to all the queues
            x2.push(min);
            x3.push(min);
            x5.push(min);

        }
        return uglyNumbers[n-1];
    }
};

int main(){
    Solution sol;
    cout << sol.nthUglyNumber(10) << endl;
}