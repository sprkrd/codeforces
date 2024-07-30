#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

constexpr i64 M = 998244353;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    i64 n;
    cin >> n;
    i64 k;
    cin >> k;

    vector<i64> dp((n+1)*(k+1)*2);
    dp[0] = dp[1] = 1;

    for (i64 i = 1; i <= n; ++i)
    {
        for (i64 j = 0; j <= min(k,i); ++j)
        {
            for (i64 repeated_last = 0; repeated_last < 2; ++repeated_last)
            {
                dp[i*(k+1)*2 + j*2 + repeated_last] =
                    (dp[(i-1)*(k+1)*2 + max(i64(0),j-1)*2] +
                    dp[max(i64(0),i-1-!repeated_last)*(k+1)*2 + j*2 + 1])%M;
            }
        }
    }
    cout << dp[(n-1)*(k+1)*2 + (k-1)*2+1] << endl;
}
