/*
*OpenKattis
*nastyhacks
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int N = 0;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int r, e, c;
        cin >> r >> e >> c;
        
        int no_ad = r;
        int yes_ad = e - c;

        string verdict = "decisions decisions";
        if (yes_ad > no_ad)
            verdict = "advertise";
        else if (yes_ad == no_ad)
            verdict = "does not matter";
        else
            verdict = "do not advertise";

        cout << verdict << endl;
    }

    return 0;
}