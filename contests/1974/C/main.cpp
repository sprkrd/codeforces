#include <bits/stdc++.h>
using namespace std;

typedef array<int,2> Key;
typedef vector<map<Key,multiset<int>>> Index;

size_t count_beautiful_triplets(const Index& index)
{
    size_t count = 0;
    for (size_t i = 0; i < 3; ++i)
    {
        for (const auto&[key, mset] : index[i])
        {
            for (auto it = mset.begin(); it != mset.end();)
            {
                size_t count_same = mset.count(*it);
                count += count_same*(mset.size()-count_same);
                advance(it, count_same);
            }
        }
    }
    count /= 2;
    return count;
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
        for (int& x : a)
        {
            cin >> x;
        }

        Index index(3);

        for (size_t i = 0; i < a.size()-2; ++i)
        {
            index[0][Key{a[i+1],a[i+2]}].insert(a[i]);
            index[1][Key{a[i],a[i+2]}].insert(a[i+1]);
            index[2][Key{a[i],a[i+1]}].insert(a[i+2]);
        }

        auto beautiful_triplets = count_beautiful_triplets(index);
        cout << beautiful_triplets << endl;
    }
}
