#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int number[11];
int operators[4]; // + - * / 개수
vector<char> operator_in_a_row;
int minResult = INT_MAX;
int maxResult = INT_MIN;
bool visited[10];
vector<char> seq;
int debugging = 0;

// void eff_dfs(int calc, int cnt){
//     if(cnt == N-1){
//         debugging++;
//         maxResult = max(maxResult, calc);
//         minResult = min(minResult, calc);
//         return;
//     }
//     else{
//         if(operators[0] > 0){
//             operators[0]--;
//             eff_dfs(calc + number[cnt+1], cnt+1);
//             operators[0]++;
//         }
//         if(operators[1] > 0){
//             operators[1]--;
//             eff_dfs(calc - number[cnt+1], cnt+1);
//             operators[1]++;
//         }
//         if(operators[2] > 0){
//             operators[2]--;
//             eff_dfs(calc * number[cnt+1], cnt+1);
//             operators[2]++;
//         }
//         if(operators[3] > 0){
//             operators[3]--;
//             eff_dfs(calc / number[cnt+1], cnt+1);
//             operators[3]++;
//         }
//     }
// }

// int main(){
//     cin >> N;
//     for(int i=0; i<N; i++){
//         cin >> number[i];
//     }
//     for(int i=0; i<4; i++){
//         cin >> operators[i];
//     }

//     eff_dfs(number[0], 0);

//     cout << maxResult << endl;
//     cout << minResult << endl;
//     cout << endl << "total cases: " << debugging << endl;
// }

// 근데 무조건 (N-1)!이라 비효율적
void dfs(int cnt){
    if(cnt == N-1){
        debugging++;
        int result = number[0];
        for(int i=0; i<N-1; i++){
            switch(seq[i]){
                case '+':
                    result += number[i+1];
                    break;

                case '-':
                    result -= number[i+1];
                    break;

                case '*':
                    result *= number[i+1];
                    break;

                case '/':
                    result /= number[i+1];
                    break;
            }
        }
        maxResult = max(maxResult, result);
        minResult = min(minResult, result);

        return;
    }
    else{
        for(int i=0; i<N-1; i++){
            // operator_in_a_row[i] == operator_in_a_row[i-1] && visited[i-1]==0: 중복 원소들 중 가장 앞 원소만 쓰겠다. 
            if(i>0){ if(operator_in_a_row[i] == operator_in_a_row[i-1] && visited[i-1]==0) continue; }
            if(visited[i] == 0){
                seq.push_back(operator_in_a_row[i]);
                visited[i] = 1;
                dfs(cnt+1);
                visited[i] = 0;
                seq.pop_back();
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> number[i];
    }
    for(int i=0; i<4; i++){
        cin >> operators[i];
    }

    for(int i=0; i<operators[0]; i++){
        operator_in_a_row.push_back('+');
    }
    for(int i=0; i<operators[1]; i++){
        operator_in_a_row.push_back('-');
    }
    for(int i=0; i<operators[2]; i++){
        operator_in_a_row.push_back('*');
    }
    for(int i=0; i<operators[3]; i++){
        operator_in_a_row.push_back('/');
    }

    dfs(0);

    cout << maxResult << endl;
    cout << minResult << endl;
    cout << endl << "total cases: " << debugging << endl;
}