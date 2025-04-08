// sw 20934 방울 마술

#include <iostream>
#include <string>

using namespace std;

int findBallfinder(string S, int K)
{
    int position;
    if (S == "0..")
    {
        position = 0;
    }
    else if (S == ".0.")
    {
        position = 1;
    }
    else if (S == "..0")
    {
        position = 2;
    }

    for (int i = 0; i < K; ++i)
    {
        if (position == 0)
        {
            position = 1;
        }
        else if (position == 1)
        {
            if (i % 2 == 0)
            {
                position = 0;
            }
            else
            {
                position = 2;
            }
        }
        else if (position == 2)
        {
            position = 1;
        }
    }
    return position;
}

int main()
{
    int T;
    cin >> T;

    for (int testcase = 1; testcase <= T; ++testcase)
    {
        string S;
        int K;
        cin >> S >> K;

        int result = findBallfinder(S, K);
        cout << "#" << testcase << "result" << endl;
    }
    return 0;
}