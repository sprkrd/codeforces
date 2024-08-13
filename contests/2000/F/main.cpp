#include <bits/stdc++.h>
using namespace std;


struct Rectangle
{
    int w, h;

    int measure() const
    {
        return min(w,h);
    }

    int area() const
    {
        return w*h;
    }

    bool operator<(const Rectangle& other) const
    {
        pair<int,int> m1(area(), measure());
        pair<int,int> m2(other.area(), other.measure());
        return m1<m2;
    }
};


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
        int k;
        cin >> k;
        vector<int> a(n);
        for (auto& x : a)
        {
            cin >> x;
        }
        vector<int> b(n);
        for (auto& x : b)
        {
            cin >> x;
        }

        priority_queue<Rectangle,vector<Rectangle>,less<Rectangle>> q;

        for (int i = 0; i < n; ++i)
        {
            q.push(Rectangle{a[i],b[i]});
        }

        int ops = 0;
        int points = 0;
        while (points < k && !q.empty())
        {
            auto r = q.top();
            q.pop();
            ++points;
            if (r.w < r.h)
            {
                ops += r.w;
                r.h--;
            }
            else
            {
                ops += r.h;
                r.w--;
            }

            if (r.w>0 && r.h>0)
            {
                q.push(r);
            }
        }

        if (q.empty())
        {
            ops = -1;
        }

        cout << ops << endl;
    }
}
