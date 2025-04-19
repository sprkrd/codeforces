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
        string s;
        cin >> s;
        
        int min_l = 0;
        int max_l = 0;
        
        vector<int> a(n);
        for (int i = 1; i < n; ++i)
        {
            if (s[i-1] == '<') a[i] = min_l = min_l-1;
            else a[i] = max_l = max_l+1;
        }
        for (int i = 0; i < n; ++i)
        {
            if (i!=0) cout << ' ';
            cout << (a[i]-min_l+1);
        }
        cout << endl;
    }
}
