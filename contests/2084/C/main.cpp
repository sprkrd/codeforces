#include <bits/stdc++.h>
using namespace std;

vector<int> permindex(const vector<int>& p)
{
    vector<int> index(p.size()+1);
    int i = 0;
    for (int n : p)
    {
        index[n] = i++;
    }
    return index;
}

void swap_positions(vector<int>& vec, vector<int>& vecindex, int i, int j)
{
    swap(vecindex[vec[i]], vecindex[vec[j]]);
    swap(vec[i], vec[j]);
}

bool doit(vector<int> a, vector<int> b, vector<pair<int,int>>& ops)
{
    int n = a.size();

    auto index_a = permindex(a);
    auto index_b = permindex(b);

    bool accepteq = n%2 == 1;

    for (int i = 0; i < n/2; ++i)
    {
        if (a[i] == b[i])
        {
            if (!accepteq)
            {
                return false;
            }
            swap_positions(a, index_a, i, n/2);
            swap_positions(b, index_b, i, n/2);
            ops.emplace_back(i+1, n/2+1);
            --i;
            accepteq = false;
        }
        else if (a[i]!=b[n-i-1] || b[i]!=a[n-i-1])
        {
            int j = index_b[a[i]];
            if (b[i] != a[j])
            {
                return false;
            }
            swap_positions(a, index_a, j, n-i-1);
            swap_positions(b, index_b, j, n-i-1);
            ops.emplace_back(j+1, n-i);
        }
    }

    return true;
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

        vector<pair<int,int>> ops;
        if (doit(a, b, ops))
        {
            cout << ops.size() << endl;
            for (auto[i,j] : ops)
            {
                cout << i << ' ' << j << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
