#include <bits/stdc++.h>
using namespace std;


int eval(unsigned omit, const string& s)
{
    vector<int> v;
    for (unsigned i = 0; i < s.size(); ++i)
    {
        if (i>0 && i-1 == omit)
        {
            v.back() = v.back()*10 + s[i]-'0';
        }
        else
        {
            v.push_back(s[i]-'0');
        }
    }
    int ans = 0;
    int running_product = v[0];
    for (unsigned i = 1; i < v.size(); ++i)
    {
        if (running_product <= 1 || v[i] <= 1)
        {
            running_product *= v[i];
        }
        else
        {
            ans += running_product;
            running_product = v[i];
        }
    }
    ans += running_product;
    return ans;
}

int eval(const string& s)
{
    int ans = numeric_limits<int>::max();
    for (unsigned i = 0; i < s.size()-1; ++i)
    {
        ans = min(ans, eval(i, s));
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
        string s;
        cin >> s;

        if (s.size() > 3 && s.find('0') != string::npos)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << eval(s) << endl;
        }
    }
}
