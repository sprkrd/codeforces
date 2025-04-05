#include <bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a, T b)
{
    while (b)
    {
        T r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool cando(vector<uint64_t> a)
{
    int n = a.size();
    sort(a.begin(), a.end());

    vector<int> gcd_multiples(a.size(), -1);

    uint64_t gcd_left = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            uint64_t gcd_right_multiples = 0;
            for (int j = i+1; j < n; ++j)
            {
                if (a[j]%a[i] == 0)
                {
                    gcd_right_multiples = gcd(a[j], gcd_right_multiples);
                }
            }
            if (gcd(gcd_left, gcd_right_multiples) == a[i])
            {
                return true;
            }
        }
        else if (a[i] == gcd_left)
        {
            return true;
        }
        gcd_left = gcd(a[i], gcd_left);
    }
    return false;
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
        vector<uint64_t> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }

        cout << (cando(a)? "Yes" : "No") << endl;

    }
}
