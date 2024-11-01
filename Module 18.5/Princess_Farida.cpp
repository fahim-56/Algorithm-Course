#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 10005;
ll dp[N];
int knaspchak(vector<int> v, int n)
{
    // cout << n << endl;
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int op1 = knaspchak(v, n - 2) + v[n];
    int op2 = knaspchak(v, n - 1);
    return dp[n] = max(op1, op2);
}
int main()
{
    int t;
    cin >> t;
    int cnt = 1;
    vector<int> v;
    while (t--)
    {
        v.clear();
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        cout << "Case " << cnt++ << ": " << knaspchak(v, n - 1) << endl;
    }

    return 0;
}