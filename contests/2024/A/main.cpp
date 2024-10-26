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
        int a;
        cin >> a;
        int b;
        cin >> b;
        int ans = min(max(2*a - b, 0), a);
        cout << ans << endl;
    }
}
