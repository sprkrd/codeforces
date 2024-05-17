#include <bits/stdc++.h>
using namespace std;


void sort3(int& x, int& y, int& z)
{
    if (z<y)
    {
        swap(y,z);
    }
    if (y<x)
    {
        swap(x,y);
    }
    if (z<y)
    {
        swap(y,z);
    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        int sum = p1+p2+p3;
        if (sum%2 == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            int count = 0;
            while (p2)
            {
                ++count; 
                --p2;
                --p3;
                sort3(p1,p2,p3);
            }
            cout << count << endl;
        }
    }
}
