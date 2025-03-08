#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(nlogn) greedy -> LIS 풀이
// class Solution {
// public:
//     int binary_search(vector<int>& seq, int key){
//         int low=0;
//         int high=seq.size()-1;
//         int mid=0;

//         while(low <= high){
//             mid = low + (high-low)/2; // (low+high)/2 해도 되는데, low+(high-low)/2가 overflow에 있어 더 안전함. 
//             if(mid == key) return key;
//             else if(mid < key) low = mid + 1;
//             else high = mid - 1;
//         }
//         return low;
//     }
//     bool increasingTriplet(vector<int>& nums) {
//         vector<int> seq; // triplet을 저장할 배열(오름차순 정렬되어있으니 이진탐색 가능)
//         int n=nums.size();
//         seq.push_back(nums[0]);

//         for(int i=1; i<n; i++){
//             // seq의 마지막 원소 값보다 큰 값 발견 시 추가
//             if(nums[i] > seq[seq.size()-1]) seq.push_back(nums[i]); 
//             else{
//                 // seq의 적절한 자리를 찾아 교체. (추가가 아니라 교체임)
//                 // nt idx = binary_search(seq, nums[i]);와 동치
//                 int idx = std::lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
//                 seq[idx] = nums[i];
//             }
//             if(seq.size() >= 3) return true;
//         }
//         return false;
//     }
// };

// O(n) greedy
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX;
        int second = INT_MAX;

        for(int i=0; i<n; i++){
            // 순열의 첫번째 값 업데이트
            if(nums[i] <= first) first = nums[i]; 

            // 순열의 첫번째 값보다 큰 값이 발견되고(<- 위의 조건문에서 <가 아닌 <=를 쓴 이유), 기존 두번째 값보다 작을때 업데이트
            else if(nums[i] <= second) second = nums[i];

            // 순열의 첫번째, 두번째 값보다 큰 값이 발견되면(<- 위의 두 조건문에서 <가 아닌 <=를 쓴 이유) triplet 완성
            else return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,1,5,0,4,6};
    cout << sol.increasingTriplet(nums) << endl;
}