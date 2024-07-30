#include <bits/stdc++.h>
using namespace std;


vector<int> toposort(const vector<int>& p)
{
    int n = p.size() + 1;
    vector<bool> marked(n);

    vector<int> sorted;
    for (int i = 0; i < n; ++i)
    {
        stack<pair<int,bool>> stk;
        stk.emplace(i, false);
        while (!stk.empty())
        {
            auto[u,done] = stk.top();
            stk.pop();
            if (marked[u])
            {
                continue;
            }
            if (done)
            {
                marked[u] = true;
                sorted.push_back(u);
            }
            else
            {
                stk.emplace(u, true);
                if (u > 0)
                {
                    stk.emplace(p[u-1]-1, false);
                }
            }
        }
    }

    reverse(sorted.begin(), sorted.end());

    return sorted;
}


int main()
{
    constexpr int INF = numeric_limits<int>::max();

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
        vector<int> p(n-1);
        for (auto& x : p)
        {
            cin >> x;
        }

        vector<bool> is_leaf(n, true);
        for (int u : p)
        {
            is_leaf[u-1] = false;
        }

        vector<int> max_increase(n, INF);

        for (int u : toposort(p))
        {
            if (u == 0)
            {
                continue;
            }

            int backup_value;
            if (is_leaf[u])
            {
                max_increase[u] = 0;
                backup_value = a[u];
            }
            else
            {
                backup_value = min(max_increase[u], (max_increase[u] + a[u])/2);
            }
            max_increase[p[u-1]-1] = min(max_increase[p[u-1]-1], backup_value);
        }

        int ans = a[0] + max_increase[0];
        cout << ans << endl;
    }
}
