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

        vector<uint64_t> cumsum(n);
        cumsum[0] = a[0];
        for (int i = 0; i < n; ++i)
        {
            cumsum[i] = cumsum[i-1] + a[i];
        }

        string s;
        cin >> s;

        uint64_t max_score = 0;
        int l = 0;
        int r = n-1;

        while (r-l+1 > 1)
        {
            if (s[l] == 'L' && s[r] == 'R')
            {
                max_score += cumsum[r] - cumsum[l] + a[l];
                ++l;
                --r;
            }
            else
            {
                l += s[l] == 'R';
                r -= s[r] == 'L';
            }
        }

        cout << max_score << endl;
    }
}
