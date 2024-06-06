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
        vector<int> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        int min_max = numeric_limits<int>::max();
        for (int i = 1; i < n; ++i)
        {
            min_max = min(min_max, max(a[i-1], a[i]));
        }
        cout << (min_max-1) << endl;
    }
}
