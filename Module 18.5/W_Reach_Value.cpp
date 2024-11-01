#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool is_reached(ll i, ll n)
{
    if (i == n)
        return true;
    if (i > n)
        return false;
    if (is_reached(i * 20, n))
        return true;

    return is_reached(i * 10, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (is_reached(1, n))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}