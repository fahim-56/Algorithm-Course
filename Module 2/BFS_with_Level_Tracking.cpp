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
    queue<int> q;
    vector<int> v(n, 0);
    vector<int> level(n, -1);
    // bool temp[n] = {false};
    int src;
    cin >> src;
    q.push(src);
    v[src] = 1;
    level[src] = 0;
    // temp[src] = true;
    while (!q.empty())
    {
        cout << q.front() << " -> " << level[q.front()] << endl;
        for (int x : a[q.front()])
        {
            if (!v[x]) //   ==0
            {
                q.push(x);
                v[x] = 1;
                level[x] = level[q.front()] + 1;
                // temp[x] = true;
            }
        }
        q.pop();
    }
    // print the unconected graph level -1
    
    // for (int i = 0; i < n; i++)
    // {
    //     if (temp[i] == false)
    //     {
    //         cout << i << " -> " << level[i] << endl;
    //     }
    // }

    return 0;
}