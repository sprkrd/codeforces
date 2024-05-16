#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<double,int>> negatives, positives;
    negatives.reserve(N);
    positives.reserve(N);
    for (int i = 1; i <= N; ++i)
    {
        double x;
        cin >> x;
        if (x < 0)
        {
            negatives.emplace_back(x, i);
        }
        else
        {
            positives.emplace_back(x, i);
        }
    }
    sort(positives.begin(), positives.end());
    sort(negatives.begin(), negatives.end(), greater<pair<double,int>>());

    if (!positives.empty() && !negatives.empty())
    {
        cout << "{d:";
    }

    if (!positives.empty())
    {
        cout << "{d:";
        bool first = true;
        for (auto[x,i] : positives)
        {
            if (!first)
            {
                cout << ',';
            }
            cout << i;
            first = false;
        }
        cout << '}';
    }

    if (!negatives.empty())
    {
        if (!positives.empty())
        {
            cout << ',';
        }
        cout << "{d:";
        bool first = true;
        for (auto[x,i] : negatives)
        {
            if (!first)
            {
                cout << ',';
            }
            cout << i;
            first = false;
        }
        cout << "}";
    }

    if (!positives.empty() && !negatives.empty())
    {
        cout << "}";
    }

    cout << endl;
    
}
