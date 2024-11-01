#include <bits/stdc++.h>
using namespace std;
int dp[101];
int knapsack(vector<int> &nums, int n)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(knapsack(nums, n - 2) + nums[n], knapsack(nums, n - 1));
}
int rob(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int n = nums.size();
    int ans = knapsack(nums, n - 1);
    return ans;
}
class Solution
{
public:
    int dp[101];
    int Sum(int n, vector<int> &nums)
    {
        if (n < 0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n] = max((Sum(n - 2, nums) + nums[n]), Sum(n - 1, nums));
    }
    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int ans=Sum(n, nums);
        return ans;
    }
};
int main()
{
    vector<int> nums;
    for (int i = 1; i <= 5; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << rob(nums) << endl;
    return 0;
}