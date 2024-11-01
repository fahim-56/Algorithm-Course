#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> arr[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> v;
        if (arr[x].empty())
        {
            cout << "-1" << endl;
            continue;
        }
        for (int k : arr[x])
        {
            v.push_back(k);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int k : v)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}