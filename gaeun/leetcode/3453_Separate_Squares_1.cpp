#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double calcAreaDifference(vector<vector<int>>& squares, double h){
        double aboveArea=0, belowArea=0;
        for(int i=0; i<squares.size(); i++){
            double x=squares[i][0];
            double y=squares[i][1];
            double l=squares[i][2];

            if(h<=y) aboveArea += l*l;
            else if(h>y && h<y+l){
                aboveArea += l*(l+y-h);
                belowArea += l*(h-y);
            }
            else belowArea += l*l;
        }
        return aboveArea - belowArea;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = INT_MAX, mid = 0, answer = 0, possibleMid = 0;
        while(low <= high){
            mid = low+(high-low)/2;
            
            if(answer == mid) break;

            if(calcAreaDifference(squares, mid) > 0){ 
                low = mid; //real number라서 low = mid + 1; 하면 안됨
            }
            else{ // calcAreaDifference(squares, mid) == 0일때도 high를 내리니까 최소 높이를 보장해줌. 
                high = mid; // real number라서 high = mid - 1; 하면 안됨
            }
            answer = mid;
            
        }

        // 모든 사각형이 겹치지 않을 때 최소 높이 찾기 -> 이 로직 안써도 돼
        // double possibleAns;
        // for(auto s:squares){
        //     // 최소 높이 갱신
        //     if(answer >= (double)(s[1]+s[2])) possibleAns = std::max(possibleAns, (double)s[1]+s[2]);

        //     // 겹치는 사각형 발생 시 trash 값으로
        //     if(answer > (double)s[1] && answer < (double)(s[1]+s[2])) possibleAns = DBL_MAX;
        // }
        //return min(answer, possibleAns);

        return answer;
    }
};