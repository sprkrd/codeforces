#include <bits/stdc++.h>
using namespace std;

bool isgood(int a)
{
    int p = 1;
    int e = 0;
    bool z = true;
    while (a > 10)
    {
        int d = a%10;
        z = d == 0;
        e += p*d;
        p *= 10;
        a /= 10;
    }
    return (a == 10 && e >= 2 && !z);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        if (isgood(a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
