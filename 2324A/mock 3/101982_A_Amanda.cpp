/*
*CodeForces
*101982 - A. Exam
*Code by: Amanda Lim
*/

// Empty. Tinatamad ako mag-solve

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    string yours, friends;
    cin >> yours >> friends;

    int same = 0, notsame = 0;
    for (int i = 0; i < (int) yours.size(); i++) {
        if (yours[i] == friends[i])
            same++;
        else
            notsame++;
    }

    if (k < same)
        cout << k << endl;
    else
        cout <<  << endl;

    return 0;
}