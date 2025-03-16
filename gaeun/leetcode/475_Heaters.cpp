#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX

using namespace std;

class Solution {
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            sort(houses.begin(), houses.end());
            sort(heaters.begin(), heaters.end());
    
            vector<int> RHS;
            vector<int> LHS;
            vector<int> result;
    
            RHS.resize(houses.size(), INT_MAX);
            LHS.resize(houses.size(), INT_MAX);
            result.resize(houses.size());
    
            // RHS
            for(int i=0, k=0; i<houses.size() && k<heaters.size();){
                if(houses[i] <= heaters[k]){
                    RHS[i] = heaters[k] - houses[i];
                    i++;
                } 
                else{
                    k++;
                }
            }
    
            // LHS
                {
                if(houses[i] >= heaters[k]){
                    LHS[i] = houses[i] - heaters[k];
                    i--;
                }
                else{
                    k--;
                }
            }
            
            for(int i=0; i<result.size(); i++){
                result[i] = min(RHS[i], LHS[i]);
            }
    
            return *max_element(result.begin(), result.end());
        }
    };

int main(){
    Solution sol;
    vector<int> houses = {1,2,3,4,5,7,8,9,10};
    vector<int> heaters = {3,6,9};

    cout << sol.findRadius(houses, heaters) << endl;
    
}