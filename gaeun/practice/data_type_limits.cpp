#include <iostream>
#include <climits>
#include <cfloat> // FLT, DBL의 MIN, MAX 매크로

using namespace std;

int main(){
    cout << "INT_MIN: " << INT_MIN << " INT_MAX: " <<INT_MAX << endl;
    cout << "LONG_MIN: " << LONG_MIN << " LONG_MAX: " <<LONG_MAX << endl;
    cout << "LLONG_MIN: " << LLONG_MIN << " LLONG_MAX: " <<LLONG_MAX << endl;
}