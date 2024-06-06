#include <bits/stdc++.h>
using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    while (b)
    {
        int m = a%b;
        a = b;
        b = m;
    }
    return a;
}

uint64_t lcm(uint64_t a, uint64_t b)
{
    return a/gcd(a,b)*b;
}

struct Fraction
{
    uint64_t num, den;

    Fraction operator+(const Fraction& other) const
    {
        uint64_t lcm_den = lcm(den,other.den);
        Fraction ans{lcm_den/den*num + lcm_den/other.den*other.num, lcm_den};
        ans.simplify();
        return ans;
    }

    Fraction operator*(uint64_t s) const
    {
        Fraction ans{num*s, den};
        ans.simplify();
        return ans;
    }

    bool less_than_one() const
    {
        return num < den;
    }

    void simplify()
    {
        uint64_t gcd_num_den = gcd(num, den);
        num /= gcd_num_den;
        den /= gcd_num_den;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> k(n);
        for (auto& x : k)
        {
            cin >> x;
        }

        Fraction sum{0, 1};
        for (int i = 0; i < n; ++i)
        {
            sum = sum + Fraction{1, (uint64_t)k[i]};
        }


        if (!sum.less_than_one())
        {
            cout << -1 << endl;
        }
        else
        {
            vector<Fraction> x(n);
            for (int i = 0; i < n; ++i)
            {
                x[i] = Fraction{sum.den, sum.num*k[i]};
                x[i].simplify();
            }

            uint64_t lcm_den = 1;
            for (int i = 0; i < n; ++i)
            {
                lcm_den = lcm(lcm_den, x[i].den);
            }

            for (int i = 0; i < n; ++i)
            {
                if (i > 0)
                {
                    cout << ' ';
                }
                uint64_t x_i = lcm_den/x[i].den*x[i].num;
                cout << x_i;
            }
            cout << endl;
        }
    }
}
