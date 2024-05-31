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
        int l,r;
        cin >> l >> r;
        int x = 1;
        int nops = 0;
        while (x*2 <= r)
        {
            x *= 2;
            ++nops;
        }
        cout << nops << endl;
    }
}
