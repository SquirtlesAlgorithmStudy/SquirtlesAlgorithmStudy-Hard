#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
vector<vector<int>> grid;
int dir[4] = {1,2,3,4}; // 상,하,좌,우
vector<int> selected;
int maxBlock = 0;

void move_up(){
    for(int c=1; c<=N; c++){
        int cnt = 0;
        int nextNum = INT_MAX;
        bool isUpdated[21][21] = {0,};
        for(int r=1; r<=N; r++){
            if(grid[r][c] == 0){
                cnt++;
                continue;
            }
            if(grid[r][c] == nextNum && isUpdated[r-cnt-1][c] == 0){
                grid[r-cnt-1][c] = 2*nextNum;
                nextNum = 2*nextNum;
                grid[r][c] = 0;
                isUpdated[r-cnt-1][c] = 1;
                cnt++;
            }
            else{
                grid[r-cnt][c] = grid[r][c];
                nextNum = grid[r][c];
                if(cnt > 0) grid[r][c] = 0;
            }
            if(nextNum != INT_MAX) maxBlock = max(maxBlock, nextNum);
        }
    }
}

void move_down(){
    for(int c=1; c<=N; c++){
        int cnt = 0;
        int nextNum = INT_MAX;
        bool isUpdated[21][21] = {0,};
        for(int r=N; r>=1; r--){
            if(grid[r][c] == 0){
                cnt++;
                continue;
            }
            if(grid[r][c] == nextNum && isUpdated[r+cnt+1][c] == 0){
                grid[r+cnt+1][c] = 2*nextNum;
                nextNum = 2*nextNum;
                grid[r][c] = 0;
                isUpdated[r+cnt+1][c] = 1;
                cnt++;
            }
            else{
                grid[r+cnt][c] = grid[r][c];
                nextNum = grid[r][c];
                if(cnt > 0) grid[r][c] = 0;
            }
            if(nextNum != INT_MAX) maxBlock = max(maxBlock, nextNum);
        }
    }
}
void move_left(){
    for(int r=1; r<=N; r++){
        int cnt = 0;
        int nextNum = INT_MAX;
        bool isUpdated[21][21] = {0,};
        for(int c=1; c<=N; c++){
            if(grid[r][c] == 0){
                cnt++;
                continue;
            }
            if(grid[r][c] == nextNum && isUpdated[r][c-cnt-1] == 0){
                grid[r][c-cnt-1] = 2*nextNum;
                nextNum = 2*nextNum;
                grid[r][c] = 0;
                isUpdated[r][c-cnt-1] = 1;
                cnt++;
            }
            else{
                grid[r][c-cnt] = grid[r][c];
                nextNum = grid[r][c];
                if(cnt > 0) grid[r][c] = 0;
            }
            if(nextNum != INT_MAX) maxBlock = max(maxBlock, nextNum);
        }        
    }
}

void move_right(){
    for(int r=1; r<=N; r++){
        int cnt = 0;
        int nextNum = INT_MAX;
        bool isUpdated[21][21] = {0,};
        for(int c=N; c>=1; c--){
            if(grid[r][c] == 0){
                cnt++;
                continue;
            }
            if(grid[r][c] == nextNum && isUpdated[r][c+cnt+1] == 0){
                grid[r][c+cnt+1] = 2*nextNum;
                nextNum = 2*nextNum;
                grid[r][c] = 0;
                isUpdated[r][c+cnt+1] = 1;
                cnt++;
            }
            else{
                grid[r][c+cnt] = grid[r][c];
                nextNum = grid[r][c];
                if(cnt > 0) grid[r][c] = 0;
            }
            if(nextNum != INT_MAX) maxBlock = max(maxBlock, nextNum);
        }
    }
}

void comb(int depth){
    if(depth == 5){
        vector<vector<int>> tmp = grid;
        for(int i=0; i<selected.size(); i++){
            if(selected[i] == 1) move_up();
            else if(selected[i] == 2) move_down();
            else if(selected[i] == 3) move_left();
            else if(selected[i] == 4) move_right();
        }
        grid = tmp;
    }
    else{
        for(int i=0; i<4; i++){
            selected.push_back(dir[i]);
            comb(depth+1);
            selected.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    grid.resize(N+1,vector<int>(N+1));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }        
    }

    comb(0);
    cout << maxBlock << "\n";

    // debugging
    // int input;
    // vector<vector<int>> tmp = grid;
    // while(1){
    //     cout << "\n" << "Enter a direction: ";
    //     cin >> input;
    //     if(input == 9) break;
        
    //     if(input == 1) move_up();
    //     if(input == 2) move_down();
    //     if(input == 3) move_left();
    //     if(input == 4) move_right();

    //     for(int i=1; i<=N; i++){
    //         for(int j=1; j<=N; j++){
    //             cout << grid[i][j] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "maxBlock: " << maxBlock << "\n";
    // }
}