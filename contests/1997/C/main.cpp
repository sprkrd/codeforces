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
        stack<int> stk;
        stk.push(0);
        int D = 0;
        for (int i = 1; i < n; ++i)
        {
            if ((s[i] == '_' && !stk.empty()) || s[i] == ')')
            {
                D += i - stk.top();
                stk.pop();
            }
            else
            {
                stk.push(i);
            }
        }
        cout << D << endl;
    }
}
