#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int wt[n];
    int val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int w;
    cin >> w;
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                int a1 = dp[i - 1][j - wt[i - 1]] + val[i - 1];
                int a2 = dp[i - 1][j];
                dp[i][j] = max(a1, a2);
            }
            else
            {
                int a2 = dp[i - 1][j];
                dp[i][j] = a2;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}