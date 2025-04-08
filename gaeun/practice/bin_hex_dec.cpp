#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string hexStr = "1F7"; // 503
    string binStr = "00010001"; // 17
    int hexToDec = stoi(hexStr, nullptr, 16);
    int binToDec = stoi(binStr, nullptr, 2);
    cout << hexToDec << "\n" << bitset<12>(hexToDec) << "\n";
    cout << binToDec << "\n" << hex << binToDec << "\n";

}