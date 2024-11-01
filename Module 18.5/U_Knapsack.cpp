#include <bits/stdc++.h>
using namespace std;
const int N = 21, W = 1001;
int dp[N][W];
int knaspsack(int n, int w, int wt[], int val[])
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] <= w)
    {
        int op1 = knaspsack(n - 1, w - wt[n - 1], wt, val) + val[n - 1];
        int op2 = knaspsack(n - 1, w, wt, val);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        return dp[n][w] = knaspsack(n - 1, w, wt, val);
    }
}
int main()
{
    int n, w;
    cin >> n >> w;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knaspsack(n, w, wt, val) << endl;
    return 0;
}