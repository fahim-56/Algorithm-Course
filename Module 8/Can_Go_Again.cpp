#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e18;
class edge
{
public:
    long long int u, v, w;
    edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<edge> elist;
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        elist.push_back(edge(a, b, c));
    }
    long long int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = N;
    }

    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (edge x : elist)
        {
            if (dis[x.u] < N && dis[x.u] + x.w < dis[x.v])
            {
                dis[x.v] = dis[x.u] + x.w;
            }
        }
    }
    bool flag = false;
    for (edge x : elist)
    {
        if (dis[x.u] < N && dis[x.u] + x.w < dis[x.v])
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        if (!flag)
        {
            if (dis[k] == N)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[k] << endl;
            }
        }
    }

    return 0;
}