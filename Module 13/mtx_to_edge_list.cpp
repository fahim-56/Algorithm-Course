// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int mtx[n][n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> mtx[i][j];
//         }
//     }
//     vector<pair<int, int>> edgelist;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (mtx[i][j] == 1)
//             {
//                 edgelist.push_back({i, j});
//             }
//         }
//     }
//     for (auto x : edgelist)
//     {
//         cout << x.first << " " << x.second << endl;
//     }
//     return 0;
// }
// 3
// 0 1 0
// 1 0 1
// 1 1 0

#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u, v, w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n;
    cin >> n;
    int mtx[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mtx[i][j];
        }
    }
    vector<edge> edgelist;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mtx[i][j] > 0)
            {
                edgelist.push_back(edge(i, j, mtx[i][j]));
            }
        }
    }
    for (auto x : edgelist)
    {
        cout << x.u << " " << x.v << " " << x.w << endl;
    }
    return 0;
}
// 4
// 0 5 -1 -1
// -1 0 6 -1
// -1 -1 0 7
// -1 8 7 0