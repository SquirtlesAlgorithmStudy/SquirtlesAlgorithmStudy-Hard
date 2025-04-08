// sw 20955 xy 문자열1
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canTransform(string S, string E)
{
    while (E.length() > S.length())
    {
        if (E.back() == 'X')
        {
            E.pop_back();
        }
        else if (E.back() == 'Y')
        {
            E.pop_back();
            reverse(E.begin(), E.end());
        }
    }
    return S == E;
}

int main()
{
    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        string S, E;
        cin >> S >> E;

        if (canTransform(S, E))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
