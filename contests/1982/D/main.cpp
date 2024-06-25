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
        int m;
        cin >> m;
        int k;
        cin >> k;

        vector<vector<i64>> a(n, vector<i64>(m));
        for (auto& row : a)
        {
            for (auto& x : row)
            {
                cin >> x;
            }
        }

        vector<string> b(n);
        for (auto& row : b)
        {
            cin >> row;
        }

        vector<vector<i64>> cumsum(n, vector<i64>(m));
        i64 height_diff = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cumsum[i][j] = ((b[i][j]=='0') - (b[i][j]=='1'));
                height_diff += ((b[i][j]=='0') - (b[i][j]=='1'))*a[i][j];
                if (i > 0)
                {
                    cumsum[i][j] += cumsum[i-1][j];
                }
                if (j > 0)
                {
                    cumsum[i][j] += cumsum[i][j-1];
                }
                if (i>0 && j>0)
                {
                    cumsum[i][j] -= cumsum[i-1][j-1];
                }
            }
        }

        if (height_diff == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        i64 ans = 0;

        for (int i = k-1; i < n; ++i)
        {
            for (int j = k-1; j < m; ++j)
            {
                i64 coef = cumsum[i][j];
                if (i - k >= 0)
                {
                    coef -= cumsum[i-k][j];
                }
                if (j - k >= 0)
                {
                    coef -= cumsum[i][j-k];
                }
                if (i - k >= 0 && j - k >= 0)
                {
                    coef += cumsum[i-k][j-k];
                }
                ans = gcd(ans, coef);
            }
        }

        if (ans!=0 && height_diff%ans == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
