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
        int m;
        cin >> m;
        string s;
        cin >> s;
        vector<int> ind(m);
        for (auto& x : ind)
        {
            cin >> x;
        }
        string c;
        cin >> c;

        multiset<int> ind_left(ind.begin(), ind.end());
        multiset<char> chr_left(c.begin(), c.end());

        while (!ind_left.empty())
        {
            auto it = ind_left.begin();
            int count = ind_left.count(*it);
            while (count > 1)
            {
                chr_left.erase(--chr_left.end());
                it = ind_left.erase(it);
                --count;
            }
            s[*it-1] = *chr_left.begin();
            chr_left.erase(chr_left.begin());
            ind_left.erase(it);
        }
        cout << s << endl;
    }
}
