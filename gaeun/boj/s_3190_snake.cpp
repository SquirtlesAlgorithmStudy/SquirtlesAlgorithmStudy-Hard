#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

int N,K,L;
int grid[101][101]={0,};
deque<pair<int,int>> snake;
queue<pair<int,char>> command;
int time=0;
pair<int,char> currCommand;
string dir = "right";

string convertDir(char cmd);
bool valid(pair<int, int> nextHead);
void move_snake(pair<int, int> nextHead);

int main(){
    cin >> N;
    cin >> K;
    for(int i=0; i<K; i++){
        int c, r;
        cin >> c >> r;
        grid[c][r] = 1;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        int t;
        char c;
        cin >> t >> c;
        command.push({t,c});
    }

    snake.push_front({1,1});
    currCommand = command.front();
    command.pop();

    while(1){
        // check the command
        if(time == currCommand.first){
            dir = convertDir(currCommand.second);
            if(!command.empty()){
                currCommand = command.front();
                command.pop();
            }
        }

        // decide snake's movement
        pair<int, int> head = snake.front();
        if(dir == "up"){
            head.first -= 1;
        }
        else if(dir == "down"){
            head.first += 1;
        }
        else if(dir == "left"){
            head.second -= 1;
        }
        else if(dir == "right"){
            head.second += 1;
        }

        // check terminate codition
        time++;
        if(valid(head)){
            move_snake(head);
        }
        else break; // game over
    }
    cout << time << endl;
}

string convertDir(char cmd){
    if(cmd == 'L') // turn left
    {
        if(dir == "up") return "left";
        if(dir == "down") return "right";
        if(dir == "left") return "down";
        if(dir == "right") return "up";
    }
    else if(cmd == 'D') // turn right
    {
        if(dir == "up") return "right";
        if(dir == "down") return "left";
        if(dir == "left") return "up";
        if(dir == "right") return "down";
    }
}
bool valid(pair<int, int> nextHead){
    // 벽 체크
    if(nextHead.first < 1 || nextHead.first > N || nextHead.second < 1 || nextHead.second > N){
        return false;
    }

    // 뱀 몸 체크
    if(find(snake.begin(), snake.end(), nextHead) != snake.end()){
        return false;
    }

    return true;
}
void move_snake(pair<int, int> nextHead){
    snake.push_front(nextHead);

    // 사과 먹음
    if(grid[nextHead.first][nextHead.second] == 1){
        grid[nextHead.first][nextHead.second] = 0;
    }
    // 사과 없으면 꼬리 줄여
    else{
        snake.pop_back();
    }
}
