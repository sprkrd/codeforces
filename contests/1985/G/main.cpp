#include <bits/stdc++.h>
using namespace std;

int64_t powmod(int64_t b, int64_t e, int64_t m)
{
    if (e == 0)
    {
        return 1;
    }
    auto ans_2 = powmod(b, e/2, m);
    auto ans = (ans_2 * ans_2) % m;
    if (e%2)
    {
        ans = (ans*b)%m;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int64_t l;
        cin >> l;
        int64_t r;
        cin >> r;
        int64_t k;
        cin >> k;

        if (k > 9)
        {
            cout << 0 << endl;
        }
        else
        {

            int64_t x = 1 + 9 / k;
            int64_t ans = powmod(x, r, 1000000007);
            ans -= powmod(x, l, 1000000007);
            if (ans < 0)
            {
                ans += 1000000007;
            }
            cout << ans << endl;
        }
    }
}
