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
        int64_t c;
        cin >> c;
        vector<int64_t> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        a[0] += c;
        vector<int64_t> cummax_rl(n);
        cummax_rl[n-1] = a[n-1];
        for (int i = n-2; i >= 0; --i)
        {
            cummax_rl[i] = max(a[i], cummax_rl[i+1]);
        }

        int first_max_idx = max_element(a.begin(), a.end()) - a.begin();

        vector<int> ans(n);
        int64_t csum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == first_max_idx)
            {
                ans[i] = 0;
            }
            else if (i == n-1 || a[i] + csum >= cummax_rl[i+1])
            {
                ans[i] = i;
            }
            else
            {
                ans[i] = i + 1;
            }
            csum += a[i];
        }

        cout << ans[0];
        for (int i = 1; i < n; ++i)
        {
            cout << ' ' << ans[i];
        }
        cout << endl;
    }
}
