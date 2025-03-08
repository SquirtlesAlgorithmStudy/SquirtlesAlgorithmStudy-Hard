#include <iostream>
#include <bitset>
using namespace std;

int main(){
    // binary number: 접두어 0b 사용
    int a = 0b001;
    int b = 0b011; 

    // xnor = ~(xor), xor은 ^
    cout << ~(a^b) << endl; // -3 출력: int로 선언된 a와 b는 실제 0000...001, 0000...011임. xor하면 0000...010이고, xnor하면 1111...101임.2의 보수로 0000...010 + 1 = 0000...011 = -3임. 
    cout << (~(a^b) & 0b111) << endl; // bit masking을 해줘야 기대한 101에 해당하는 5 출력.
    cout << bitset<3>(~(a^b)) << endl; // bitset 함수 써야 101 출력. 
}