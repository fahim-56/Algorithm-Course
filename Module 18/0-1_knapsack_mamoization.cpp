#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000, maxW = 1000;
int dp[maxN][maxW];
int knapchak(int n, int w, int wt[], int val[])
{
    // sob product jodi furay jai othoba bag jodi full hoye jai
    if (n == 0 || w == 0)
        return 0;
    // checking j current product er value bag er capacity theke coto kina
    // coto hole
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] <= w)
    {
        // ei product er value ki count korbo kina
        // jodi kori taile eitar value jog kore eitar weigt biyog kore pass koro
        int a1 = knapchak(n - 1, w - wt[n - 1], wt, val) + val[n - 1];
        // ar jobi na kori taile porer gula khujo
        int a2 = knapchak(n - 1, w, wt, val);
        //  boro ta return
        return dp[n][w] = max(a1, a2);
    }
    else
    {
        // current product er value bag er capacity theke boro hole to ar nite parbo na tai baki gula te check kori
        int a2 = knapchak(n - 1, w, wt, val);
        dp[n][w] = a2;
        return a2;
    }
}
int main()
{
    int n;
    cin >> n;
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
    int w;
    cin >> w;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <=w; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapchak(n, w, wt, val) << endl;
    return 0;
}