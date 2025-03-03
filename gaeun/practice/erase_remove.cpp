#include <iostream>
#include <algorithm> // remove()
#include <vector> // erase()

using namespace std;

int main(){
    // 3을 지워봅시다!
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4,5};
    vector<int> v3 = {1,2,3,4,5};

    // remove(start, end, target): start ~ end-1 범위에서 target 삭제
    cout << "v1.size(): " << v1.size() << endl;
    auto it = remove(v1.begin(), v1.end(), 3); // target 없앤 만큼 마지막 원소 뒤에 dummy 와르르

    for(int num:v1) cout << num << " ";
    cout << endl << "it - v1.begin(): " << it - v1.begin() << endl; // dummy 시작 위치 반환
    cout << "v1.size() after remove: " << v1.size() << endl; // size 안바뀜
    cout << endl;


    // 1. erase(start, end): start ~ end-1 범위의 원소 모두 삭제
    // 2. erase(target_address): target_address의 원소 삭제
    cout << "v2.size(): " << v2.size() << endl;
    auto it2 = v2.erase(v2.begin()+2); // 실제로 제거하지만 제거 대상의 주소를 넣어줘야한다는 불편함

    for(int num:v2) cout << num << " ";
    cout << endl << "it2 - v2.begin(): " << it2 - v2.begin() << endl; // 제거된 대상의 위치 + 1 반환
    cout << "v2.size() after remove: " << v2.size() << endl; // size 줄어듦
    cout << endl;


    // 깔끔하게 벡터 원소 지우기: v3.erasae(remove(v3.begin(), v3.end(), 3));과 동치
    auto it3 = remove(v3.begin(), v3.end(), 3); // target 지우기. 단, dummy 생성됨
    v3.erase(it3, v3.end()); // dummy 지우기

    for(int num:v3) cout << num << " ";
    cout << endl << "v3.size(): " << v3.size() << endl;


}