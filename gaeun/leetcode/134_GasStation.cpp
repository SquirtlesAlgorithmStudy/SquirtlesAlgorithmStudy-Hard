/*
 - n개의 circular gas station, i번째 gas station에는 gas[i]의 가스량 보유
 - i번째에서 i+1번째의 travel cost는 cost[i].
 - CW로 circuit를 완주할 수 있는 starting gas station index 반환해라
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// brute force: time limit exceed
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int gasStationNum = gas.size();
//         vector<int> diff;
//         queue<int> qIdx;
//         int startIdx=0;
//         int tank=0;
//         int ans=0;

//         // 10^5
//         for(int i=0; i<gasStationNum; i++) // gas[i]-cost[i] >= 0인 i를 저장
//         {
//             diff.push_back(gas[i]-cost[i]);
//             if(gas[i]-cost[i]>0) qIdx.push(i);
//         }

//         // 10^5
//         while(!qIdx.empty())
//         {
//             startIdx = qIdx.front();
//             qIdx.pop();

//             // 10^5
//             for(int i=startIdx; i<gasStationNum+startIdx; i++) // 연료가 0 이상이면 해당 인덱스 반환
//             {
//                 int idx = i % gasStationNum;
//                 tank += diff[idx];

//                 if(tank < 0){
//                     break;
//                 }
//             }
//             if(tank >= 0) return startIdx;

//             tank = 0;
//         }
//         return -1;
//     }
// };

// Greedy sol 1
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         int consumption = 0;
//         int total = 0;
//         int startIdx = 0;

//         for(int i=0; i<n; i++){
//             consumption += gas[i] - cost[i];
//             if(consumption < 0){
//                 total += consumption;
//                 startIdx = i+1;
//                 consumption = 0;                
//             }
//         }
//         total += consumption;
//         if(total < 0){
//             return -1;
//         }
//         else return startIdx; 
//     }
// };

// greedy sol 2
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
            int sum=0;
            int currentConsuption=0;
            int startIdx=0;
            for(int i=0; i<n; i++){
                sum += gas[i]-cost[i];
            }
            if(sum < 0) return -1;
            else{
                for(int i=0; i<n; i++){
                    currentConsuption += gas[i]-cost[i];
                    if(currentConsuption < 0){
                        currentConsuption = 0;
                        startIdx = i+1;
                    }
                }
                return startIdx;
            }
        }
    };

int main(){
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    
    cout << sol.canCompleteCircuit(gas, cost) << endl;
}