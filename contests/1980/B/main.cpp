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
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);
        for (int& x : a)
        {
            cin >> x;
        }
        int value_favorite = a[f-1];
        sort(a.begin(), a.end());
        int lb = lower_bound(a.begin(), a.end(), value_favorite) - a.begin();
        int ub = upper_bound(a.begin(), a.end(), value_favorite) - a.begin();
        if (n - lb - 1 < k)
        {
            cout << "YES" << endl;
        }
        else if (n - ub < k)
        {
            cout << "MAYBE" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
