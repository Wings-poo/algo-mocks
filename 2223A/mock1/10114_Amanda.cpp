/*
*OnlineJudge
*10114 - Loansome Car Buyer
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int months, deprec;
    float down, loan;
    
    while (1) {
        cin >> months >> down >> loan >> deprec;
        if (months < 0)
            break;

        float init = down + loan;
        int ans;
    
        int mon;
        float dep;
        for (int i = 0; i < deprec; i++) {
            cin >> mon_curr >> dep_curr;
            if (i == 0)
                continue;

            if (init >= loan) {
                init -= (init*dep);
            }

            if (init < loan)
                ans = i;
        }

        if (ans == 1)
            cout << month << endl;
        else
            cout << months << endl;

    }

    return 0;
}