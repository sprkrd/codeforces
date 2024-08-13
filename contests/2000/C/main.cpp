#include <bits/stdc++.h>
using namespace std;


template<class C>
vector<int> canonical(const C& collection)
{
    typedef typename C::value_type V;
    vector<int> ans;
    ans.reserve(collection.size());
    map<V,int> tr;
    for (auto x : collection)
    {
        auto[it,inserted] = tr.emplace(x, tr.size());
        ans.push_back(it->second);
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
        vector<int> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        int m;
        cin >> m;
        vector<string> s(m);
        for (auto& x : s)
        {
            cin >> x;
        }

        auto ref = canonical(a);

        for (const auto& x : s)
        {
            if (ref == canonical(x))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }


}
