#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int dp[N];
int knaspchak(vector<int> &cost, int n)
{
    if (n < 0)
        return 0;
    if (n == 1 || n == 0)
        return cost[n];
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = min(knaspchak(cost, n - 1) + cost[n], knaspchak(cost, n - 2) + cost[n]);
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    memset(dp, -1, sizeof(dp));
    knaspchak(cost, n);
}
int main()
{
    vector<int> cost;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        cost.push_back(x);
    }
    cout << minCostClimbingStairs(cost);
    return 0;
}