/*
*OpenKattis
*integerlists
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
        string BAPC;
        cin >> BAPC;

        int N;
        cin >> N;

        char tapon;
        cin >> tapon;

        int list_of_int[N];
        for (int n = 0; n < N; n++)
            cin >> list_of_int[n] >> tapon;
        if (!N)
            cin >> tapon;

        bool error = false;
        bool reverse = false;
        int A = 0, B = N;
        for (int i = 0; i < (int) BAPC.size(); i++) {
            if (BAPC[i] == 'R')
                reverse = !reverse;
            else {
                if (A >= B) {
                    error = true;
                    break;
                }

                if (!reverse)
                    A++;
                else
                    B--;
            }
        }

        if (error)
            cout << "error" << endl;
        else {
            cout << '[';
            if (!reverse)
                for (int i = A; i < B; i++) {
                    cout << list_of_int[i];
                    if (i < (B - 1))
                        cout << ',';
                }
            else
                for (int i = B - 1; i >= A; i--) {
                    cout << list_of_int[i];
                    if (i > A)
                        cout << ',';
                }
            cout << ']' << endl;
        }
    }

    return 0;
}