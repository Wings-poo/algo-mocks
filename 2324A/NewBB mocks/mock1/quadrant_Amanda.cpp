/*
*OpenKattis
*quadrant
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x, y;
    cin >> x >> y;

    if (y > 0)
        if (x > 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    else
        if (x < 0)
            cout << 3 << endl;
        else
            cout << 4 << endl;
        
    return 0;
}