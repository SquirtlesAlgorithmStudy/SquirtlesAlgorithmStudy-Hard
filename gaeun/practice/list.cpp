#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    auto it = myList.begin();
    it++;
    for(int num:myList) cout << num << " ";
    cout << endl;
    cout << "*it: " << *it << endl;

    auto target = it;
    myList.erase(--target);
    for(int num:myList) cout << num << " ";
    cout << endl;
    cout << "*it: " << *it << endl;

}