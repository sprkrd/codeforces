#include <bits/stdc++.h>
using namespace std;


int intersection(const string& a, const string& b)
{
    int N = a.size();
    int M = b.size();
    vector<vector<int>> dp(N+1, vector<int>(M+1));

    int ans = 0;
    for (int i = N-1; i >= 0; --i)
    {
        for (int j = M-1; j >= 0; --j)
        {
            if (a[i]==b[j])
            {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else
            {
                dp[i][j] = dp[i+1][j];
            }

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string b;
        cin >> b;

        int ans = a.size() + b.size() - intersection(a,b);

        cout << ans << endl;

    }
}
