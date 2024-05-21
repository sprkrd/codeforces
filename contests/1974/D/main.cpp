#include <bits/stdc++.h>
using namespace std;

const char* symbols = "RH";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int dummy;
        string instructions;
        cin >> dummy >> instructions;

        string ans = instructions;

        map<char,int> tr{
            {'N',-1},
            {'S',-1},
            {'E',-1},
            {'W',-1},
        };

        int x = 0;
        int y = 0;

        map<char,int> count;

        bool moves[] = {false, false};

        for (size_t i = 0; i < instructions.size(); ++i)
        {
            char dir = instructions[i];
            int curr;
            if (dir == 'N' || dir == 'S')
            {
                if (y > 0)
                {
                    curr = dir=='N'? 1 : 0;
                    --y;
                }
                else if (y < 0)
                {
                    curr = dir=='N'? 0 : 1;
                    ++y;
                }
                else
                {
                    curr = moves[0]? 1 : 0;
                    y += (curr==0) ^ (dir=='S')? 1 : -1;
                }
            }
            else
            {
                if (x > 0)
                {
                    curr = dir=='E'? 1 : 0;
                    --x;
                }
                else if (x < 0)
                {
                    curr = dir=='E'? 0 : 1;
                    ++x;
                }
                else
                {
                    curr = moves[0]? 1 : 0;
                    x += (curr==0) ^ (dir=='W')? 1 : -1;
                }
            }
            moves[curr] = true;
            ans[i] = symbols[curr];
        }


        if (!moves[0] || !moves[1] || x || y)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
