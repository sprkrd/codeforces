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
        int m, n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a)
        {
            cin >> x;
        }
        for (int& x : b)
        {
            cin >> x;
        }
        cin >> m;
        vector<int> d(m);
        for (int& x : d)
        {
            cin >> x;
        }

        if (find(b.begin(),b.end(),d.back()) == b.end())
        {
            cout << "NO" << endl;
            continue;
        }

        multiset<int> pending_assignments;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
            {
                pending_assignments.insert(b[i]);
            }
        }

        for (int x : d)
        {
            auto it = pending_assignments.find(x);
            if (it != pending_assignments.end())
            {
                pending_assignments.erase(it);
            }
        }

        if (pending_assignments.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
