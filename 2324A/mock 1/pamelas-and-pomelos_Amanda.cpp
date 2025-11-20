/*
*Hackerrank - National Olympiad in Informatics - Philippines 2014 Finals
*pamelas-and-pomelos
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int I, II, III;
    cin >> I >> II >> III;
    
    int min_dist = min(abs(I), min(abs(II), abs(III)));
    if (abs(I) == min_dist)
        cout << "PAMELA I" << endl;
    if (abs(II) == min_dist)
        cout << "PAMELA II" << endl;
    if (abs(III) == min_dist)
        cout << "PAMELA III" << endl;
    return 0;
}