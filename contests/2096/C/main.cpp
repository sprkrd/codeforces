#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Chain;

void transpose(vector<vector<int>>& h)
{
    int n = h.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            swap(h[i][j], h[j][i]);
        }
    }
}

constexpr int64_t inf = numeric_limits<int64_t>::max();

int64_t doit(const vector<vector<int>>& h, const vector<int>& a)
{
    int n = h.size();
    vector<int64_t> dp(2*n, inf);
    auto at = [&](int i, int j) -> int64_t&
    {
        return dp[2*i + j];
    };
    
    at(0, 0) = 0;
    at(0, 1) = a[0];
    
    for (int i = 1; i < n; ++i)
    {
        for (int x = 0; x <= 1; ++x)
        {
            for (int y = 0; y <= 1; ++y)
            {
                bool ok = at(i-1,y)!=inf;
                for (int j = 0; j<n && ok; ++j)
                {
                    ok = h[i-1][j]+y != h[i][j]+x;
                }
                if (ok) at(i, x) = min(at(i,x), at(i-1, y) + x*a[i]);
            }
        }
    }
    
    return min(at(n-1, 0), at(n-1, 1));
}

int64_t doit(vector<vector<int>>& h, const vector<int>& a, const vector<int>& b)
{
    int64_t cost_rows = doit(h, a);
    if (cost_rows == inf) return -1;
    
    transpose(h);
    
    int64_t cost_cols = doit(h, b);
    if (cost_cols == inf) return -1;
    
    return cost_rows + cost_cols;
}

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
        vector<vector<int>> h(n,vector<int>(n));
        for (auto& row : h)
        {
            for (auto& x : row)
            {
                cin >> x;
            }
        }
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
        
        cout << doit(h,a,b) << endl;
    }
}
