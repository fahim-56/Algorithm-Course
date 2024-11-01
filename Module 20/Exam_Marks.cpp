#include <bits/stdc++.h>
using namespace std;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        w = 1000 - w;
        bool dp[n + 1][w + 1];
        dp[0][0] = true;
        for (int i = 1; i <= w; i++)
        {
            dp[0][i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][w])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}