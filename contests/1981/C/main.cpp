#include <bits/stdc++.h>
using namespace std;


bool fill(vector<int>& a, int i, int j)
{
    while (j-i > 1)
    {
        if (a[i] > a[j])
        {
            a[i+1] = a[i]/2;
            ++i;
        }
        else if (a[j] > a[i])
        {
            a[j-1] = a[j]/2;
            --j;
        }
        else if (a[i] == 1)
        {
            a[i+1] = 2*a[i];
            if (a[i+1] > 1'000'000'000)
            {
                return false;
            }
            ++i;
        }
        else
        {
            a[i+1] = a[i]/2;
            ++i;
        }
    }
    return a[i]==a[j]/2 || a[j]==a[i]/2;
}

bool fill_remaining_sequence(vector<int>& a, int i, int di)
{
    int n = a.size();
    bool divide = a[i-di]>1;
    for (; 0<=i && i<n; i+=di)
    {
        if (divide)
        {
            a[i] = a[i-di]/2;
        }
        else
        {
            a[i] = a[i-di]*2;
        }
        if (a[i] < 1 || a[i] > 1'000'000'000)
        {
            return false;
        }
        divide ^= 1;
    }
    return true;
}

bool solve(vector<int>& a)
{
    int n = a.size();
    int prev = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != -1)
        {
            if (prev == -1)
            {
                if (!fill_remaining_sequence(a, i-1, -1))
                {
                    return false;
                }
            }
            else if (!fill(a, prev, i))
            {
                return false;
            }
            prev = i;
        }
    }
    if (prev == -1)
    {
        a[0] = 1;
        prev = 0;
    }
    return fill_remaining_sequence(a, prev+1, 1);
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
        if (solve(a))
        {
            for (int i = 0; i < n; ++i)
            {
                if (i>0)
                {
                    cout << ' ';
                }
                cout << a[i];
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
