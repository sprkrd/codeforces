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
        string problems;
        cin >> n >> m >> problems;
        vector<int> count(7,0);
        for (char c : problems)
        {
            count[c-'A']++;
        }
        int ans = 0;
        for (int x : count)
        {
            ans += max(0, m-x);
        }
        cout << ans << endl;
    }
}
