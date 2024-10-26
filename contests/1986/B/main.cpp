#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

int max_neighbor(const Matrix& mat, unsigned i, unsigned j)
{
    int ans = numeric_limits<int>::min();
    if (i > 0)
    {
        ans = max(ans, mat[i-1][j]);
    }
    if (i < mat.size()-1)
    {
        ans = max(ans, mat[i+1][j]);
    }
    if (j > 0)
    {
        ans = max(ans, mat[i][j-1]);
    }
    if (j < mat[0].size()-1)
    {
        ans = max(ans, mat[i][j+1]);
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
        int m;
        cin >> m;

        Matrix a(n, vector<int>(m));
        for (auto& row : a)
        {
            for (auto& x : row)
            {
                cin >> x;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j>0)
                {
                    cout << ' ';
                }
                int v = max_neighbor(a, i, j);
                cout << min(a[i][j], v);

            }
            cout << endl;
        }
    }
}
