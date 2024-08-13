#include <bits/stdc++.h>
using namespace std;

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
        int m;
        cin >> m;
        int k;
        cin >> k;
        int w;
        cin >> w;
        vector<uint64_t> a(w);
        for (auto& x : a)
        {
            cin >> x;
        }



        vector<int> b;
        b.reserve(n*m);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int W = min(m-k,j) - max(0,j-k+1) + 1;
                int H = min(n-k,i) - max(0,i-k+1) + 1;
                b.push_back(W*H);

                //cout << (W*H) << '\t';
            }
            //cout << endl;
        }

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        uint64_t spectacle = 0;
        for (int i = 0; i < w; ++i)
        {
            spectacle += b[i]*a[i];
        }

        cout << spectacle << endl;

    }
}
