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
        int64_t n;
        cin >> n;
        int64_t m;
        cin >> m;
        int64_t r;
        cin >> r;
        int64_t c;
        cin >> c;

        int64_t ans = (m-c) + (n-r)*(1 + (m-1) + (m-1));
        cout << ans << endl;
    }
}
