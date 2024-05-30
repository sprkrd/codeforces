#include <bits/stdc++.h>
using namespace std;

bool is_strong(const string& pwd)
{
    char p = '\0';
    for (char c : pwd)
    {
        if (p != '\0')
        {
            if (isdigit(c) && !isdigit(p))
            {
                return false;
            }
            else if (isdigit(c) && c < p)
            {
                return false;
            }
            else if (!isdigit(c) && !isdigit(p) && c < p)
            {
                return false;
            }
        }
        p = c;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int dummy;
        string pwd;
        cin >> dummy >> pwd;
        cout << (is_strong(pwd)? "YES" : "NO") << endl;
    }
}
