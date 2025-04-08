#include <vector>
#include <iostream>

using namespace std;

pair<int, int> parent[50][50];

int main(){
    parent[5][1] = {1,1};
    cout << parent[5][1].first << " " << parent[5][1].second << "\n";
}