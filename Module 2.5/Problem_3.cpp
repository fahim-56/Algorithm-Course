#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> a[n];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int nd;
    cin >> nd;
    cout << a[nd].size() << endl;
    return 0;
}
