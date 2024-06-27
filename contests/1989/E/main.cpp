#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<vector<int>> dp(n+1, vector<int>(k+1));


    for (int i = 2; i <= n; ++i)
    {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= k; ++j)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]*j;
        }
    }

    cout << dp[n][k] << endl;
}
