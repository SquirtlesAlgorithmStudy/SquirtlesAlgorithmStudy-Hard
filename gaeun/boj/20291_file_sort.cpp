#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, int> m;

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;

        string ext = s.substr(s.find('.')+1);
        m[ext]++;
    }

    for(const auto& ele : m){
        cout << ele.first << " " << ele.second << endl;
    }
}