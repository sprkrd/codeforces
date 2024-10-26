#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;


ostream& operator<<(ostream& out, const multiset<int>& s)
{
    bool f = true;
    out << '{';
    for (int x : s)
    {
        if (!f) out << ", ";
        out << x;
        f = false;
    }
    return out <<'}';
}

i64 solve(int n, int k, const vector<int>& a)
{
    map<int,multiset<int>> m;
    for (int x : a)
    {
        m[x%k].insert(x);
    }

    int wildcards = n%2;

    i64 ans = 0;
    for (auto&&[mod,s] : m)
    {
        int inc = 0;
        if (s.size()%2)
        {
            if (!wildcards)
            {
                return -1;
            }
            --wildcards;

            auto it = s.begin();
            auto it_next = next(it);

            int inc1 = 0;
            while (it_next != s.end())
            {
                inc1 += *it_next - *it;
                it = next(it_next);
                it_next = next(it);
            }

            int inc2 = 0;
            it = next(s.begin());
            while (it != s.end())
            {
                it_next = next(it);
                inc2 += *it_next - *it;
                it = next(it_next);
            }

            inc = min(inc1,inc2)/k;
        }
        else
        {
            auto it = s.begin();
            while (it != s.end())
            {
                auto it_next = next(it);
                inc += *it_next - *it;
                it = next(it_next);
            }
            inc /= k;
        }
        cout << ">>> mod " << mod << ": " << s << " k: " << k << " inc: " << inc << endl;
        ans += inc;
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
        int k;
        cin >> k;
        vector<int> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        cout << solve(n, k, a) << endl;
    }
}
