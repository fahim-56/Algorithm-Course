#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int adj[n+5][n+5];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            adj[i][j] = x;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i != k)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i != j && j != k)
                    {
                        if (adj[i][k] + adj[k][j] < adj[i][j])
                        {
                            adj[i][j] = adj[i][k] + adj[k][j];
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}