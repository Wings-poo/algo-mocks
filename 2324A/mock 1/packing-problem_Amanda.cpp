/*
*Hackerrank - National Olympiad in Informatics - Philippines 2014 Finals
*packing-problem
*Code by: Amanda Lim
*/

// WA

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

        int X = W - (R1 + R1 + R2);
        int Y = R2 - X;
        int Y2;
        if (Y <= 0)
            Y2 = L - R1 - R1;
        else
            Y2 = L - R1 - R1 - Y - R2;
        
        if ((X >= 0) && (Y2 >= 0))
            cout << "PACKING GOOD" << endl;
        else
            cout << "PACKING BAD" << endl;
    }
    return 0;
}