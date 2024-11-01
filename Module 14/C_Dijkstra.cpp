#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<pair<long long int, long long int>> arr[n + 1];
    long long int dis[n + 1];
    long long int par[n + 1];
    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({v, w});
        arr[v].push_back({u, w});
    }
    for (int i = 0; i < n + 1; i++)
    {
        dis[i] = 1e18;
        par[i] = -1;
    }

    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> q;
    q.push({1, 0});
    dis[1] = 0;
    while (!q.empty())
    {
        long long int N = q.top().first;
        long long int C = q.top().second;
        q.pop();
        for (pair<long long int, long long int> x : arr[N])
        {
            long long int Cn = x.first;
            long long int Cc = x.second;
            if (C + Cc < dis[Cn])
            {
                dis[Cn] = C + Cc;
                q.push({Cn, dis[Cn]});
                par[Cn] = N;
            }
        }
    }
    if (dis[n] == 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<long long int> d;
        while (n != -1)
        {
            d.push_back(n);
            n = par[n];
        }
        reverse(d.begin(), d.end());
        for (int k : d)
        {
            cout << k << " ";
        }
    }
    return 0;
}