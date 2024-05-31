#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        uint32_t n, m;
        cin >> n >> m;

        uint32_t a_n = n;
        for (int b = 0; b < 32; ++b)
        {
            uint32_t mask = 1U<<b;
            if (!(n&mask))
            {

                uint32_t low_bits = n&(mask-1);
                if ((low_bits+1<=m && low_bits+1<n) || (mask-low_bits <= m))
                {
                    a_n |= mask;
                }
            }
        }
        cout << a_n << endl;
    }
}
