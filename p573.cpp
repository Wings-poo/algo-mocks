/*
Aug 22 2020 Mock
p573
The Snail
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int H, U, D, F;
    while (cin >> H >> U >> D >> F) {
        if (!H)
            break;
        
        int progress = 0;
        H *= 100;
        U *= 100;
        D *= 100;
        F = U*F/100;

        int day = 0;
        while ((progress >= 0) && (progress <= H)) {
            day++;

            progress += U;

            U -= F;

            if (U < 0)
                U = 0;

            if (progress <= H)
                progress -= D;
            else
                break;
        }

        if (progress < 0)
            cout << "failure";
        else
            cout << "success";
        
        cout << " on day " << day << endl;
    }
}