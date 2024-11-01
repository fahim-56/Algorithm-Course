#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int dp[N];
bool fun(int i, int n)
{
    if (i == n)
    {
        return true;
    }
    if (i > n)
    {
        return false;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    return dp[i] = fun(i + 3, n) || fun(i * 2, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }

        if (fun(1, n))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}