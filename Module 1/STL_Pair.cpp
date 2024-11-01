#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, string> p;
    p.first = 100;
    p.second = "Fahim";
    p = make_pair(10, "Fahim");
    cout << p.first << " " << p.second << endl;
    return 0;
}