#include <iostream>
#include <string>

using namespace std;

int T;

int palindrome(int front, int back, bool deleted, string str){
    while(front < back){
        if(str[front] != str[back]){
            if(deleted == 0){
                if(!palindrome(front+1, back, 1, str) || !palindrome(front, back-1, 1, str)) return 1;
                else return 2;
            }
            else return 2;            
        }
        else{
            front++;
            back--;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for(int t=1; t<=T; t++){
        string str;
        cin >> str;

        int answer = palindrome(0, str.size()-1, 0, str);
        cout << answer << "\n";
    }
}