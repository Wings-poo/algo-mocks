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

        deque <int> list_of_int (N);
        for (int n = 0; n < N; n++)
            cin >> list_of_int[n] >> tapon;
        if (!N)
            cin >> tapon;

        bool error = false;
        bool reverse = false;
        for (int i = 0; i < (int) BAPC.size(); i++) {
            if (BAPC[i] == 'R')
                reverse = !reverse;
            else {
                if (list_of_int.empty()) {
                    error = true;
                    break;
                }

                if (!reverse)
                    list_of_int.pop_front();
                else
                    list_of_int.pop_back();
            }
        }

        if (error)
            cout << "error" << endl;
        else {
            cout << '[';
            if (!reverse)
                for (int i = 0; i < (int) list_of_int.size(); i++) {
                    cout << list_of_int[i];
                    if (i < ((int) list_of_int.size() - 1))
                        cout << ',';
                }
            else
                for (int i = list_of_int.size() - 1; i >= 0; i--) {
                    cout << list_of_int[i];
                    if (i > 0)
                        cout << ',';
                }
            cout << ']' << endl;
        }
    }

    return 0;
}