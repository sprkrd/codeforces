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
        int x1;
        cin >> x1;
        int y1;
        cin >> y1;
        int x2;
        cin >> x2;
        int y2;
        cin >> y2;

        if ((x1 <= y1 && x2 >= y2) ||
            (y1 <= x1 && y2 >= x2))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
