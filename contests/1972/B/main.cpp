#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string coins;
        cin >> n >> coins;
        int u = 0;
        for (char c : coins)
        {
            u += c=='U';
        }
        cout << (u%2? "YES" : "NO") << endl;
    }
}
