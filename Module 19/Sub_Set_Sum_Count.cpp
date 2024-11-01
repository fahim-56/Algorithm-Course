#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knaspchak(int n, int w, int arr[])
{
    if (n == 0)
    {
        if (w == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (arr[n - 1] <= w)
    {
        return dp[n][w] = (knaspchak(n - 1, w - arr[n - 1], arr)) + (knaspchak(n - 1, w, arr));
    }
    else
        return dp[n][w] = knaspchak(n - 1, w, arr);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int w;
    cin >> w;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knaspchak(n, w, arr) << endl;
    return 0;
}