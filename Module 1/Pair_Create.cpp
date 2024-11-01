#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int first;
    string second;
    void Make_Pair(int a, string b)
    {
        first = a;
        second = b;
    }
};
int main()
{
    Pair a;
    // a.first = 100;
    // a.second = "Fahim";
    a.Make_Pair(100, "Fahim");
    cout << a.first << " " << a.second << endl;
    return 0;
}