#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<uint64_t> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        int count = a[0] == 0;
        uint64_t sum = a[0];
        int i_max = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[i_max])
            {
                i_max = i;
            }
            sum += a[i];
            count += a[i_max] == (sum-a[i_max]);
        }
        cout << count << endl;
    }
}
