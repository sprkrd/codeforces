#include <bits/stdc++.h>
using namespace std;

void arrange_odd(vector<int>& out, int n)
{
    iota(out.begin(), out.end(), 1);
    swap(out[0], out[1]);
}

int finisher(int n)
{
    int ans = 1;
    n >>= 1;
    while (n > 1)
    {
        ans = (ans<<1) | 1;
        n >>= 1;
    }
    return ans;
}

void arrange_even(vector<int>& out, int n)
{
    if ((n&(n-1))==0)
    {
        out[n-1] = n;
        arrange_odd(out, n-1);
    }
    else
    {
        int f = finisher(n);
        out[n-3] = n;
        out[n-2] = n-1;
        out[n-1] = f;
        int k = 1;
        for (int i = 0; i < n-3; ++i)
        {
            if (k == f)
            {
                ++k;
            }
            out[i] = k;
            ++k;
        }
    }

}

int compute_k(const vector<int>& p)
{
    int ans = 0;
    for (unsigned i = 0; i < p.size(); ++i)
    {
        if (i%2==0)
        {
            ans &= p[i];
        }
        else
        {
            ans |= p[i];
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
        int n;
        cin >> n;
        vector<int> p(n);
        if (n%2 == 0)
        {
            arrange_even(p, n);
        }
        else
        {
            arrange_odd(p, n);
        }
        cout << compute_k(p) << endl;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0) cout << ' ';
            cout << p[i];
        }
        cout << endl;
    }
}
