#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int grid[20][20];
int f,b,u,d,l,r;
int row, col;
vector<int> cmd;

void moveDice(int dir);

int main(){
    f=0, b=0, u=0, d=0, l=0, r=0;

    cin >> N >> M >> row >> col >> K;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int c;
            cin >> c;
            grid[i][j] = c;
        }
    }
    for(int i=0; i<K; i++){
        int m;
        cin >> m;
        cmd.push_back(m); 
    }

    for(int i=0; i<K; i++){
        int dir = cmd[i];
        int nextRow = row;
        int nextCol = col;
        switch(dir){
            case 1: // right
                nextCol = col+1;
                break;
            case 2: // left
                nextCol = col-1;
                break;
            case 3: // up
                nextRow = row-1;
                break;
            case 4: // down
                nextRow = row+1;
            
        }

        if(!(nextCol>=0 && nextCol<M && nextRow>=0 && nextRow<N)){
            continue;
        }
        else{
            moveDice(dir);

            row = nextRow;
            col = nextCol;

            if(grid[row][col] == 0){
                grid[row][col] = d;
            }
            else{
                d = grid[row][col];
                grid[row][col] = 0;
            }
            cout << u << endl;
        }
    }
}

void moveDice(int dir){
    int nf, nb, nu, nd, nl, nr;
    switch(dir){        
        case 1: // right
            nf=f;
            nb=b;
            nu=l;
            nd=r;
            nl=d;
            nr=u;
            break;
        case 2: // left
            nf=f;
            nb=b;
            nu=r;
            nd=l;
            nl=u;
            nr=d;
            break;
        case 3: // up
            nf=d;
            nb=u;
            nu=f;
            nd=b;
            nl=l;
            nr=r;
            break;
        case 4: // down    
            nf=u;
            nb=d;
            nu=b;
            nd=f;
            nl=l;
            nr=r;               
    }
    f=nf, b=nb, u=nu, d=nd, r=nr, l=nl;
}