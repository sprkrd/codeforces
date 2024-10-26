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
        int64_t n;
        cin >> n;
        int64_t k;
        cin >> k;
        vector<int64_t> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        int64_t presses = 0;
        int64_t offset = 0;
        sort(a.begin(), a.end());
        for (int64_t i = 0; k; ++i)
        {
            a[i] -= offset;
            int64_t presses_guaranteed = a[i]*(n-i);
            offset += a[i];
            presses += min(k, presses_guaranteed);
            k = max(int64_t(0), k - presses_guaranteed);
            if (k)
            {
                ++presses;
            }
        }
        cout << presses << endl;
    }
}
