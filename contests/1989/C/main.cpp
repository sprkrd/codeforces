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
        vector<int> b(n);
        for (auto& x : b)
        {
            cin >> x;
        }

        int m1 = 0;
        int m2 = 0;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
            {
                if (a[i] > b[i])
                {
                    m1 += a[i];
                }
                else
                {
                    m2 += b[i];
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (a[i] == b[i])
            {
                if (a[i] == 0)
                {
                    continue;
                }
                if (a[i] == 1)
                {
                    if (m1 < m2)
                    {
                        ++m1;
                    }
                    else
                    {
                        ++m2;
                    }
                }
                else
                {
                    if (m1 >= m2)
                    {
                        --m1;
                    }
                    else
                    {
                        --m2;
                    }
                }
            }
        }
        int rating = min(m1,m2);
        cout << rating << endl;
    }
}
