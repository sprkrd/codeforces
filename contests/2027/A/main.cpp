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
        vector<pair<int,int>> stamps(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> stamps[i].first >> stamps[i].second;
        }
        sort(stamps.begin(), stamps.end());

        int max_height = stamps.back().second;
        int perimeter = stamps.back().first*2 + stamps.back().second*2;
        for (int i = n-2; i >= 0; --i)
        {
            perimeter += max(0, 2*(stamps[i].second - max_height));
            max_height = max(max_height, stamps[i].second);
        }
        cout << perimeter << endl;
    }
}
