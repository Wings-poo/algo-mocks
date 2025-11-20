/*
*OnlineJudge
*10368 - Euclid’s Game
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int A, B;
    while (cin >> A >> B) {
        if (!A && !B)
            break;
        
        bool Stan = true;
        while (A && B) {
            cout << A << " " << B << endl;
            if (A >= B) {
                if (A/B > 1)
                    A -= B*(A/B - 1);
                else
                    A -= B;
            } else {
                if (B/A > 1)
                    B -= A*(B/A - 1);
                else
                    B -= A;
            }
            Stan = !Stan;
        }

        if (Stan)
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
    return 0;
}