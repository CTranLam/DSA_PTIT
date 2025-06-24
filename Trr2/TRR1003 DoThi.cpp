#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005][1005];
int b[1005][1005];
vector<pair<int, int>> v;
int bac[1005];
int main()
{   
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t, n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] && i < j)
            {
                v.push_back({i, j});
                bac[i]++;
                bac[j]++;
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << bac[i] << " ";
        }
    }
    else if (t == 2)
    {
        cout << n << " " << v.size() << endl;
        for (int i = 1; i <= v.size(); i++)
        {
            b[v[i - 1].first][i] = 1;
            b[v[i - 1].second][i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= v.size(); j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}