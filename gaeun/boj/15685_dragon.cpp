#include <iostream>
#include <stack>

using namespace std;

int grid[101][101]={0,};
int N;
int x, y, d, g;
int result = 0;

void calc_coordinate(){
    if(d==0) x+=1;
    else if(d==1) y-=1;
    else if(d==2) x-=1;
    else if(d==3) y+=1;
}

void dragon_curve(){
    stack<int> s0, s1;
    s0.push(d);
    grid[x][y] = 1;

    calc_coordinate();
    grid[x][y] = 1;

    for(int i=0; i<g; i++){
        s1 = s0;
        while(!s0.empty()){
            d = s0.top();
            s0.pop();
            d = (d+1)%4;
            calc_coordinate();
            s1.push(d);
            grid[x][y] = 1;
        }
        s0=s1;
    }

}

int countSquares(){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(grid[i][j]){
                if(grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1]) result++;
            }
        }
    }
    return result;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        dragon_curve();
    }

    cout << countSquares() << endl;
}