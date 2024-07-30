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
        string s;
        cin >> s;

        bool found = false;
        for (unsigned i = 1; i < s.size() && !found; ++i)
        {
            if (s[i-1] == s[i])
            {
                char c = s[i-1];
                found = true;
                s.insert(s.begin()+i, c=='a'?'b':'a');
            }
        }
        if (!found)
        {
            s.push_back(s.back()=='a'?'b':'a');
        }
        cout << s << endl;
    }
}
