#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string b;
        cin >> b;
        swap(a[0],b[0]);
        cout << a << ' ' << b << endl;
    }
}
