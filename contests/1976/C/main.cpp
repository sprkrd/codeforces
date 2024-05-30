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
        int n, m;
        cin >> n >> m;
        vector<int> a(n+m+1);
        vector<int> b(n+m+1);
        for (int& x : a)
        {
            cin >> x;
        }
        for (int& x : b)
        {
            cin >> x;
        }

        vector<bool> is_programmer(n+m+1);
        int n_programmers = 0;
        int n_testers = 0;
        int last_programmer = -1;
        int last_tester = -1;

        unsigned long long max_strength = 0;
        for (int i = 0; i < n + m + 1; ++i)
        {
            if ((a[i] > b[i] && n_programmers < n+1) || (b[i] >= a[i] && n_testers == m+1))
            {
                is_programmer[i] = n_programmers < n+1;
            }
            else
            {
                is_programmer[i] = n_testers >= m+1;
            }

            if (is_programmer[i])
            {
                ++n_programmers;
                last_programmer = i;
                max_strength += a[i];
            }
            else
            {
                ++n_testers;
                last_tester = i;
                max_strength += b[i];
            }
        }

        for (int i = 0; i < n + m + 1; ++i)
        {
            unsigned long long strength = max_strength;
            if (is_programmer[i])
            {
                strength -= a[i];
                if (n_programmers == n)
                {
                    strength -= b[last_tester];
                    strength += a[last_tester];
                }
            }
            else
            {
                strength -= b[i];
                if (n_testers == m)
                {
                    strength -= a[last_programmer];
                    strength += b[last_programmer];
                }
            }

            if (i>0)
            {
                cout << ' ';
            }
            cout << strength;
        }
        cout << endl;
    }
}
