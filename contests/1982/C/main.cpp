#include <bits/stdc++.h>
using namespace std;


typedef int64_t i64;

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
        i64 l;
        cin >> l;
        i64 r;
        cin >> r;
        vector<i64> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }


        int win_l = 0;
        int win_r = -1;

        i64 sum_window = 0;
        int rounds = 0;

        while (win_l < n && win_r < n)
        {
            if (sum_window < l)
            {
                ++win_r;
                if (win_r < n)
                {
                    sum_window += a[win_r];
                }
            }
            else if (sum_window > r)
            {
                sum_window -= a[win_l];
                ++win_l;
            }
            else
            {
                ++rounds;
                win_l = win_r+1;
                sum_window = 0;
            }
        }

        cout << rounds << endl;
    }
}
