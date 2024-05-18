#include <bits/stdc++.h>
using namespace std;


constexpr int max_nbits = 20;


int loneliness_bit(const vector<uint32_t>& a, int b)
{
    uint32_t mask = 1U<<b;
    unsigned max_consecutive_zeros = 0;
    unsigned current_count = 0;
    for (uint32_t x : a)
    {
        if (x&mask)
        {
            max_consecutive_zeros = max(current_count, max_consecutive_zeros);
            current_count = 0;
        }
        else
        {
            ++current_count;
        }
    }
    max_consecutive_zeros = max(max_consecutive_zeros, current_count);
    return max_consecutive_zeros==a.size()? 1 : (max_consecutive_zeros+1);
}

int loneliness(const vector<uint32_t>& a)
{
    int loneliness = 1;
    for (int b = 0; b < max_nbits; ++b)
    {
        loneliness = max(loneliness, loneliness_bit(a, b));
    }
    return loneliness;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<uint32_t> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << loneliness(a) << endl;
    }
}
