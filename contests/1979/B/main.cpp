#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        uint32_t x;
        cin >> x;
        uint32_t y;
        cin >> y;

        for (int b = 0; b < 32; ++b)
        {
            uint32_t mask = 1<<b;
            if ((x&mask) != (y&mask))
            {
                cout << mask << endl;
                break;
            }
        }
    }
}
