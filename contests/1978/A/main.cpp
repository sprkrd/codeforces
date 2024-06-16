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
        int ans = 0;
        for (int i = 0; i < n-1; ++i)
        {
            ans = max(ans, a[i] + a[n-1]);
        }
        cout << ans << endl;
    }
}
