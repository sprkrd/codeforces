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
        vector<string> g(2);
        for (auto& x : g)
        {
            cin >> x;
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 1; j < n-1; ++j)
            {
                ans += g[i].substr(j-1,3) == "x.x" &&
                       g[1-i].substr(j-1,3) == "...";
            }
        }
        cout << ans << endl;
    }
}
