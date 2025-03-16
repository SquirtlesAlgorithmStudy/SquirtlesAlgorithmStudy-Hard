// 백준 12501 퇴사

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T[16];
int P[16];
int Maxprice[16];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; --i)
    {
        if (i + T[i] <= N + 1)
        {
            Maxprice[i] = max(Maxprice[i + 1], P[i] + Maxprice[i + T[i]]);
        }
        else
        {
            Maxprice[i] = Maxprice[i + 1];
        }
    }

    cout << Maxprice[1] << endl;

    return 0;
}