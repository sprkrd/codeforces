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

        int ans = n;

        for (int i = 0; i < n; ++i)
        {
            int ans_i = i;
            for (int j = i + 1; j < n; ++j)
            {
                ans_i += a[j] > a[i];
            }
            ans = min(ans, ans_i);
        }

        cout << ans << endl;

    }
}
