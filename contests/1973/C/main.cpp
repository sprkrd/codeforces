#include <bits/stdc++.h>
using namespace std;

int argmax(const vector<int>& v)
{
    return max_element(v.begin(), v.end()) - v.begin();
}

vector<int> solve(const vector<int>& p)
{
    assert(p.size()%2 == 0);
    int offset = argmax(p) % 2;
    vector<pair<int,int>> maximums, minimums;
    for (size_t i = 0; i < p.size(); i += 2)
    {
        maximums.emplace_back(p[i+offset], i+offset);
        minimums.emplace_back(p[i+(1-offset)], i+(1-offset));
    }
    sort(maximums.begin(), maximums.end(), greater<pair<int,int>>());
    sort(minimums.begin(), minimums.end(), greater<pair<int,int>>());

    int n = p.size();
    vector<int> ans(p.size());
    for (int i = 0; i < n/2; ++i)
    {
        ans[minimums[i].second] = i + 1;
        ans[maximums[i].second] = n/2 + i + 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int& x : p)
        {
            cin >> x;
        }
        auto ans = solve(p);
        for (size_t i = 0; i < ans.size(); ++i)
        {
            if (i > 0)
            {
                cout << ' ';
            }
            cout << ans[i];
        }
        cout << endl;
    }
}

