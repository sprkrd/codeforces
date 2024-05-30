#include <bits/stdc++.h>
using namespace std;

unsigned long long count_edits(const vector<int>& a, const vector<int>& b)
{
    int last = b.back();
    unsigned long long edits = 0;
    unsigned long long min_inc = numeric_limits<int>::max();
    for (size_t i = 0; i < a.size(); ++i)
    {
        int src = a[i];
        int target = b[i];
        edits += abs(target-src);

        unsigned long long inc;
        if ((src<=last && last<=target) || (target<=last && last<=src))
        {
            inc = 1;
        }
        else
        {
            inc = 1 + min(abs(last-src), abs(last-target));
        }
        min_inc = min(inc, min_inc);
    }
    return edits + min_inc;
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
        vector<int> a(n);
        vector<int> b(n+1);
        for (int& x : a)
        {
            cin >> x;
        }
        for (int& x : b)
        {
            cin >> x;
        }
        cout << count_edits(a, b) << endl;
    }
}
