#include <bits/stdc++.h>
using namespace std;


string decode(const string& encoded)
{
    set<char> unique{encoded.begin(), encoded.end()};
    string r{unique.begin(), unique.end()};
    string decoded(encoded.size(), '.');
    for (size_t i = 0; i < decoded.size(); ++i)
    {
        size_t j = r.size() - 1 - r.find_first_of(encoded[i]);
        decoded[i] = r[j];
    }
    return decoded;
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
        string encoded;
        cin >> dummy >> encoded;
        string decoded = decode(encoded);
        cout << decoded;
        if (t)
        {
            cout << '\n';
        }
        else
        {
            cout << endl;
        }
    }
}
