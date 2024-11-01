#include <bits/stdc++.h>
#define ll long long int
using namespace std;
long long int N = 1e18;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll mtx[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mtx[i][j] = N;
            if (i == j)
            {
                mtx[i][j] = 0;
            }
        }
    }

    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        if (w < mtx[a][b])
            mtx[a][b] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mtx[i][k] + mtx[k][j] < mtx[i][j])
                {
                    mtx[i][j] = mtx[i][k] + mtx[k][j];
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (mtx[u][v] == N)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << mtx[u][v] << endl;
        }
    }

    return 0;
}