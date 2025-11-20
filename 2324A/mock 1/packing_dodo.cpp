/*
*Hackerrank - National Olympiad in Informatics - Philippines 2014 Finals
*packing-problem
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int L, W, R1, R2;
        cin >> L >> W >> R1 >> R2;

        if (W < L)
            swap(W,L);
        if (R1 < R2)
            swap(R1, R2);

        if (((R1 + R2) * (R1 + R2)) - ((W - (R1 + R2)) * (W - (R1 + R2))) < L)
            cout << "PACKING GOOD" << endl;
        else
            cout << "PACKING BAD" << endl;
    }
    return 0;
}