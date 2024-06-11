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
        uint64_t x;
        cin >> x;
        uint64_t y;
        cin >> y;
        uint64_t z;
        cin >> z;
        uint64_t k;
        cin >> k;

        uint64_t ans = 0;
        for (uint64_t xs = 1; xs <= min(x, k); ++xs)
        {
            if (k % xs != 0)
            {
                continue;
            }
            for (uint64_t ys = 1; ys <= min(y, k/xs); ++ys)
            {
                uint64_t zs = k / (xs*ys);
                if (k % (xs*ys) == 0 && zs <= z)
                {
                    uint64_t zs = k / (xs*ys);
                    uint64_t ways = (x-xs+1)*(y-ys+1)*(z-zs+1);
                    ans = max(ans,ways);
                }
            }
        }
        cout << ans << endl;
    }
}
