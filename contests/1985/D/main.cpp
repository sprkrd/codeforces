#include <bits/stdc++.h>
using namespace std;

pair<int,int> find_top(const vector<string>& map)
{
    int n = map.size();
    int m = map[0].size();
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (map[i][j] == '#')
            {
                return {i,j};
            }
        }
    }
    assert(false);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<string> map(n);
        for (auto& x : map)
        {
            cin >> x;
        }
        auto[i_top,j_middle] = find_top(map);
        int i_bottom = i_top+1;
        while (i_bottom<n && map[i_bottom][j_middle]=='#')
        {
            ++i_bottom;
        }
        int i_middle = (i_top + i_bottom)/2;
        ++i_middle;
        ++j_middle;
        cout << i_middle << ' ' << j_middle << endl;
    }
}
