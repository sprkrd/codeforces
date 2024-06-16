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
        uint64_t k;
        cin >> k;


        vector<int> p(n);
        iota(p.begin(), p.end(), 1);

        for (int i = 0; i < n/2 && k; ++i)
        {
            uint64_t inc = 2*(p[n-1-i] - p[i]);
            if (inc <= k)
            {
                k -= inc;
                swap(p[n-1-i], p[i]);

            }
        }

        if (k == 2)
        {
            for (int i = 0; i < n-1; ++i)
            {
                int inc = abs(i+1 - p[i+1]) + abs(i+2 - p[i]) - (abs(i+1-p[i]) + abs(i+2-p[i+1]));
                if (inc == 2)
                {
                    swap(p[i], p[i+1]);
                    k = 0;
                    break;
                }
            }
        }

        if (k == 0)
        {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i)
            {
                if (i > 0)
                {
                    cout << ' ';
                }
                cout << p[i];
            }
            cout << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
