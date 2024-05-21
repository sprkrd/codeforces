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
        int x, y;
        cin >> x >> y;

        int num_screens_2x2 = (y+1)/2;
        int extra_space = 7*(num_screens_2x2 - y%2) + (y%2)*11;
        int num_screens = num_screens_2x2;
        if (x > extra_space)
        {
            int extra_screens = ((x - extra_space)+14)/15;
            num_screens += extra_screens;
        }

        cout << num_screens << endl;
    }
}
