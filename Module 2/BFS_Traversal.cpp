#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cout << "Enter Node & Edge Number :" << endl;
    cin >> n >> e;
    cout << "Enter Nodes with Chold node :" << endl;
    vector<int> list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    // 6 6
    // 3 0
    // 0 1
    // 0 2
    // 1 2
    // 2 4
    // 4 5
    // 0
    cout << "Enter Source Node :" << endl;
    int src;
    cin >> src;
    bool visited[n] = {false};
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        cout << q.front() << " ";
        for (int x : list[q.front()])
        {
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }
        q.pop();
    }

    // 0 3 1 2 4 5
    return 0;
}