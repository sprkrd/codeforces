#include <bits/stdc++.h>
using namespace std;

void sort3(int& x, int& y, int& z)
{
    if (y < x)
    {
        swap(x, y);
    }
    if (z < y)
    {
        swap(y, z);
    }
    if (y < x)
    {
        swap(x, y);
    }

}

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
        int x2;
        cin >> x2;
        int x3;
        cin >> x3;

        sort3(x1,x2,x3);

        int ans = abs(x1-x2) + abs(x2-x3);
        cout << ans << endl;
    }
}
