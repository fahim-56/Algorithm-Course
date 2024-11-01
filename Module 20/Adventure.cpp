#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000, maxW = 1000;
int dp[maxN][maxW];
int knapchak(int n, int w, int wt[], int val[])
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] <= w)
    {
        int a1 = knapchak(n - 1, w - wt[n - 1], wt, val) + val[n - 1];
        int a2 = knapchak(n - 1, w, wt, val);
        return dp[n][w] = max(a1, a2);
    }
    else
    {
        int a2 = knapchak(n - 1, w, wt, val);
        dp[n][w] = a2;
        return a2;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int w;
        cin >> w;
        int wt[n];
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        int val[n];
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << knapchak(n, w, wt, val) << endl;
    }
    return 0;
}