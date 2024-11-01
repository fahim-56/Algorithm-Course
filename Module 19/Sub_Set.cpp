#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool knapschak(int n, int w, int arr[])
{
    if (n == 0)
    {
        if (w == 0)
            return true;
        else
            return false;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (arr[n - 1] <= w)
    {
        bool op1 = knapschak(n - 1, w - arr[n - 1], arr);
        bool op2 = knapschak(n - 1, w, arr);
        return dp[n][w] = (op1 || op2);
    }
    else
    {
        return dp[n][w] = knapschak(n - 1, w, arr);
    }
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

    if (knapschak(n, w, arr))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}