#include <bits/stdc++.h>
using namespace std;


//int inversions(const array<int,2>& a1, const array<int,2>& a2)
//{
    //int inv = 0;
    //inv = (a1[0] > a2[0]) +
          //(a1[0] > a2[1]) +
          //(a1[1] > a2[0]) +
          //(a1[1] > a2[1]);
    //return inv;
//}

//vector<int> toposort(const vector<array<int,2>>& a)
//{
    //int n = a.size();
    //vector<bool> marked(n);

    //vector<int> sorted;
    //for (int i = 0; i < n; ++i)
    //{
        //stack<pair<int,bool>> stk;
        //stk.emplace(i, false);
        //vector<bool> current_path(n);
        //while (!stk.empty())
        //{
            //auto[u,expanded] = stk.top();
            //stk.pop();
            //if (marked[u])
            //{
                //continue;
            //}
            //if (expanded)
            //{
                //current_path[u] = false;
                //marked[u] = true;
                //sorted.push_back(u);
            //}
            //else
            //{
                //assert(!current_path[u]);
                //current_path[u] = true;
                //stk.emplace(u, true);
                //for (int v = 0; v < n; ++v)
                //{
                    //if (u == v) continue;
                    //if (inversions(a[u],a[v]) < inversions(a[v],a[u]))
                    //{
                        //stk.emplace(v, false);
                    //}
                //}
            //}
        //}
    //}

    //reverse(sorted.begin(), sorted.end());

    //return sorted;
//}

bool cmp(const array<int,2>& a1, const array<int,2>& a2)
{
    int max_1 = max(a1[0], a1[1]);
    int max_2 = max(a2[0], a2[1]);
    int min_1 = min(a1[0], a1[1]);
    int min_2 = min(a2[0], a2[1]);
    return max_1<max_2 || (max_1==max_2 && min_1<min_2);
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
        vector<array<int,2>> a(n);
        for (auto& ai : a)
        {
            cin >> ai[0] >> ai[1];
        }

        sort(a.begin(), a.end(), cmp);

        for (int i = 0; i < n; ++i)
        {
            if (i)
            {
                cout << ' ';
            }
            cout << a[i][0] << ' ' << a[i][1];
        }
        cout << endl;


        //auto p = toposort(a);
        //for (int i = 0; i < n; ++i)
        //{
            //if (i)
            //{
                //cout << ' ';
            //}
            //cout << a[p[i]][0] << ' ' << a[p[i]][1];
        //}
        //cout << endl;
    }
}
