#include <bits/stdc++.h>
using namespace std;


typedef uint64_t u64;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h;
        cin >> h;
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        vector<int> c(n);
        for (auto& x : c)
        {
            cin >> x;
        }

        priority_queue<pair<u64,int>,vector<pair<u64,int>>,greater<pair<u64,int>>> q;

        for (int i = 0; i < n; ++i)
        {
            q.emplace(1, i);
        }

        u64 t = 1;
        while (h > 0)
        {
            auto[t_ready, i] = q.top();
            q.pop();
            t = max(t, t_ready);
            h -= a[i];
            q.emplace(t+c[i], i);
        }
        cout << t << endl;
    }
}
