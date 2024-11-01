#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> arr[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    queue<int> q;
    vector<bool> vis(n, false);
    vector<int> l(n, -1);
    q.push(0);
    vis[0] = true;
    l[0] = 0;
    int lv;
    cin >> lv;
    vector<int> val;
    while (!q.empty())
    {

        for (int x : arr[q.front()])
        {
            if (vis[x] == false)
            {
                q.push(x);
                vis[x] = true;
                l[x] = l[q.front()] + 1;
                if (l[x] == lv)
                {
                    val.push_back(x);
                }
            }
        }
        q.pop();
    }
    sort(val.begin(), val.end(), greater<int>());
    for (int x : val)
    {
        cout << x << " ";
    }
    return 0;
}