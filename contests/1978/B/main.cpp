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
        int64_t a;
        cin >> a;
        int64_t b;
        cin >> b;

        int64_t k = max(int64_t(0), min(n, b-a));

        int64_t p = a*(n-k) + b*(b+1)/2 - (b-k)*(b-k+1)/2;

        cout << p << endl;
    }
}
