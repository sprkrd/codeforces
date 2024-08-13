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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }

        vector<bool> occupied(n+2);

        bool ok = true;
        occupied[a[0]] = true;
        for (int i = 1; i < n && ok; ++i)
        {
            ok = occupied[a[i]-1] || occupied[a[i]+1];
            occupied[a[i]] = true;
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
