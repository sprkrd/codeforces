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
        int k;
        cin >> k;
        vector<int> l(n);
        for (auto& x : l)
        {
            cin >> x;
        }
        vector<int> r(n);
        for (auto& x : r)
        {
            cin >> x;
        }
        
        vector<int> min_l_r(n);
        
        uint64_t ans = 1;
        for (int i = 0; i < n; ++i)
        {
            ans += max(l[i], r[i]);
            min_l_r[i] = min(l[i], r[i]);
        }
        sort(min_l_r.begin(), min_l_r.end(), greater<int>());
        for (int i = 0; i < k-1; ++i)
        {
            ans += min_l_r[i];
        }
        cout << ans << endl;
    }
}
