#include <iostream>
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
        double low = std::min(squares[0][1], squares[1][1]);
        double high = std::max(squares[0][1]+squares[0][2], squares[1][1]+squares[1][2]);
        double mid = low+(high-low)/2;

        while(abs(calcAreaDifference(squares, mid)) > 0.00005){
            cout << "calcAreaDifference(squares, mid): " << calcAreaDifference(squares, mid) << endl;
            mid = low+(high-low)/2;

            if(calcAreaDifference(squares, mid) > 0){
                low = mid + 1;
            }
            else if(calcAreaDifference(squares, mid) < 0){
                high = mid - 1;
            }
            else{
                break;
            }
            cout << "mid: " << mid << endl;
        }
        return mid;
    }
};

int main(){

}