#include <iostream>
#include <vector>
#include <queue>
#define UP 0 
#define DOWN 1 
#define LEFT 2 
#define RIGHT 3

#define UNKNOWN 0 
#define UPPER 1 
#define NORTH 2 
#define SOUTH 3 
#define EAST 4 
#define WEST 5

using namespace std;

int N = 8, M = 3, F = 2;
int unknown[21][21] = {
    {4, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 3, 3, 3, 1, 0, 1},
    {0, 1, 3, 3, 3, 1, 0, 1},
    {0, 1, 3, 3, 3, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1}
};
int east[21][21] = {
    {1, 1, 1},
    {0, 0, 0},
    {0, 1, 1}
};

int west[21][21] = {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
};

int south[21][21] = {
    {0, 0, 1},
    {1, 0, 0},
    {1, 0, 1}
};

int north[21][21] = {
    {0, 0, 0},
    {1, 0, 0},
    {1, 1, 1}
};

int upper[21][21] = {
    {2, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
};

bool visitedUnknown[21][21] = {0,};
bool visitedUpper[21][21] = {0,};
bool visitedNorth[21][21] = {0,};
bool visitedSouth[21][21] = {0,};
bool visitedEast[21][21] = {0,};
bool visitedWest[21][21] = {0,};

struct timeWallCoordInfo {
    int sr, er, sc, ec;
};
timeWallCoordInfo timeWallCoord;

struct weirdTimeInfo {
    int r, c, v, d;
};
vector<weirdTimeInfo> weirdTime;

struct locationInfo {
    int r, c, dim;
};
queue<locationInfo> q;

bool successFlag = 0;
int answer = 0;

void spreadWeired(){
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    for(int i=0; i<weirdTime.size(); i++){
        weirdTimeInfo curr = weirdTime[i];
        unknown[curr.r][curr.c] = 5;

        if(answer % curr.v != 0) continue;

        int nr = curr.r + dr[curr.d];
        int nc = curr.c + dc[curr.d];

        if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
        if(!(unknown[nr][nc] == 0 || unknown[nr][nc] == 5)) continue;

        unknown[nr][nc] = 5;
        weirdTime[i].r = nr; weirdTime[i].c = nc;
    }
}

locationInfo getNextCoord(locationInfo loc, int dir){
    locationInfo next;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int nr = loc.r + dr[dir];
    int nc = loc.c + dc[dir];

    if(loc.dim == UNKNOWN){
        if(nr >= timeWallCoord.sr && nr <= timeWallCoord.er && nc >= timeWallCoord.sc && nc<=timeWallCoord.ec){
            if(dir == DOWN){
                next.r = M-1;
                next.c = loc.c;
                next.dim = NORTH;
            }
            else if(dir == UP){
                next.r = M-1;
                next.c = loc.c;
                next.dim = SOUTH;
            }
            else if(dir == RIGHT){
                next.r = M-1;
                next.c = loc.r;
                next.dim = WEST;
            }
            else if(dir == LEFT){
                next.r = M-1;
                next.c = loc.r;
                next.dim = EAST;
            }
        }
        else{
            next.r = nr;
            next.c = nc;
            next.dim = loc.dim;
        }
    }
    else{
        if(nr<0 || nr>=M || nc<0 || nc>=M){
            if(loc.dim == UPPER){
                if(nr<0){
                    next.r = 0;
                    next.c = loc.c;
                    next.dim = NORTH;
                }
                if(nr>=M){
                    cout << "south\n";
                    next.r = 0;
                    next.c = loc.c;
                    next.dim = SOUTH;
                }
                if(nc<0){
                    next.r = 0;
                    next.c = loc.r;
                    next.dim = WEST;
                }
                if(nc>=M){
                    next.r = 0;
                    next.c = loc.r;
                    next.dim = EAST;
                }
            }
            else if(loc.dim == NORTH){
                if(nr<0){
                    next.r = 0;
                    next.c = loc.c;
                    next.dim = UPPER;
                }
                if(nr>=M){
                    next.r = timeWallCoord.sr-1;
                    next.c = loc.c;
                    next.dim = UNKNOWN;
                }
                if(nc<0){
                    next.r = loc.r;
                    next.c = M-1;
                    next.dim = EAST;
                }
                if(nc>=M){
                    next.r = loc.r;
                    next.c = 0;
                    next.dim = WEST;
                }

            }
            else if(loc.dim == WEST){
                if(nr<0){
                    next.r = M-1;
                    next.c = loc.c;
                    next.dim = UPPER;
                }
                if(nr>=M){
                    next.r = timeWallCoord.er+1;
                    next.c = loc.c;
                    next.dim = UNKNOWN;
                }
                if(nc<0){
                    next.r = loc.r;
                    next.c = M-1;
                    next.dim = NORTH;
                }
                if(nc>=M){
                    next.r = loc.r;
                    next.c = 0;
                    next.dim = SOUTH;
                }
                
            }
            else if(loc.dim == SOUTH){
                if(nr<0){
                    next.r = M-1;
                    next.c = loc.c;
                    next.dim = UPPER;
                }
                if(nr>=M){
                    next.r = timeWallCoord.er+1;
                    next.c = loc.c;
                    next.dim = UNKNOWN;
                }
                if(nc<0){
                    next.r = loc.r;
                    next.c = M-1;
                    next.dim = WEST;
                }
                if(nc>=M){
                    next.r = loc.r;
                    next.c = 0;
                    next.dim = EAST;
                }                
            }
            else if(loc.dim == EAST){
                if(nr<0){
                    next.r = loc.c;
                    next.c = M-1;
                    next.dim = UPPER;
                }
                if(nr>=M){
                    next.r = loc.c;
                    next.c = timeWallCoord.ec+1;
                    next.dim = UNKNOWN;
                }
                if(nc<0){
                    next.r = loc.r;
                    next.c = M-1;
                    next.dim = SOUTH;
                }
                if(nc>=M){
                    next.r = loc.r;
                    next.c = 0;
                    next.dim = NORTH;
                }                
            }

        }
        else{
            next.r = nr;
            next.c = nc;
            next.dim = loc.dim;
        }
    }
    return next;
}

bool validLocation(locationInfo loc){
    switch(loc.dim){
        case UNKNOWN:
            if(loc.r<0 || loc.r>=N || loc.c<0 || loc.c>=N) return false;
            if(visitedUnknown[loc.r][loc.c]) return false;
            if(unknown[loc.r][loc.c] == 4){
                visitedUnknown[loc.r][loc.c] = 1;
                successFlag = 1;
                return true;
            }
            else if(unknown[loc.r][loc.c] == 0){
                visitedUnknown[loc.r][loc.c] = 1;
                return true;
            } 
            else return false;
            break;

        case UPPER:
            if(visitedUpper[loc.r][loc.c]) return false;
            if(upper[loc.r][loc.c] == 0){
                visitedUpper[loc.r][loc.c] = 1;
                return true;
            } 
            else return false;
            break;

        case NORTH:
            if(visitedNorth[loc.r][loc.c]) return false;
            if(north[loc.r][loc.c] == 0){
                visitedNorth[loc.r][loc.c] = 1;
                return true;
            } 
            else return false;
            break;

        case SOUTH:
            if(visitedSouth[loc.r][loc.c]) return false;
            if(south[loc.r][loc.c] == 0){
                visitedSouth[loc.r][loc.c] = 1;
                return true;
            }
            else return false;
            break;

        case WEST:
            if(visitedWest[loc.r][loc.c]) return false;
            if(west[loc.r][loc.c] == 0){
                visitedWest[loc.r][loc.c] = 1;
                return true;
            }
            else return false;
            break;

        case EAST:
            if(visitedEast[loc.r][loc.c]) return false;
            if(east[loc.r][loc.c] == 0){
                visitedEast[loc.r][loc.c] = 1;
                return true;
            }
            else return false;
            break;
    }
}

bool bfs(){
    while(!q.empty()){
        int repeat = q.size();
        answer++;
        spreadWeired();
        cout << "answer: " << answer << "\n";
        for(int r=0; r<repeat; r++){
            locationInfo curr = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                locationInfo next = getNextCoord(curr, i);
                if(!validLocation(next)) continue;
                q.push(next);
                if(successFlag) return true;
            }
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    bool timeWallFlag = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!timeWallFlag && unknown[i][j] == 3){
                timeWallFlag = 1;
                timeWallCoord.sr = i;
                timeWallCoord.er = i+M-1;
                timeWallCoord.sc = j;
                timeWallCoord.ec = j+M-1;
            }
        }
    }

    // 타임머신 위치 탐색
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(upper[i][j] == 2){
                locationInfo timemachine;
                timemachine.r = i;
                timemachine.c = j;
                timemachine.dim = UPPER;
                q.push(timemachine);
                visitedUpper[i][j] = 1;
            }
        }
    }

    // 시간 이상 현상 초기화
    weirdTime.push_back({0, 7, 1, 14});
    weirdTime.push_back({6, 3, 3, 2});

    if(!bfs()) cout << -1 << "\n";
    else cout << answer << "\n";
}
