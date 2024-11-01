#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n, m;

ll mtx[20][20];
ll maxNum(ll i, ll j)
{
    if (i == n - 1 && j == m - 1)
    {
        return mtx[i][j];
    }
    else if (i == n || j == m)
    {
        return INT_MIN;
    }
    int op1 = maxNum(i + 1, j);
    int op2 = maxNum(i, j + 1);
    return max(op1, op2) + mtx[i][j];
}

int main()
{
    cin >> n >> m;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mtx[i][j];
        }
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= m; j++)
    //     {
    //         cout << mtx[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << maxNum(0, 0) << endl;
    return 0;
}