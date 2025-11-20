/*
*OpenKattis
*rockpaperscissors
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N, K;
    while (cin >> N) {
        if (!N)
            break;
        
        cin >> K;

        int win[N] = {0}, lose[N] = {0};
        int games = K*N*(N-1)/2;
        for (int k = 0; k < games; k++) {
            int p1, p2;
            string m1, m2;
            
            cin >> p1 >> m1 >> p2 >> m2;

            if (m1 == "rock") {
                if (m2 == "paper") {
                    win[p2-1]++;
                    lose[p1-1]++;
                }
                if (m2 == "scissors") {
                    win[p1-1]++;
                    lose[p2-1]++;
                }
            }

            if (m1 == "paper") {
                if (m2 == "scissors") {
                    win[p2-1]++;
                    lose[p1-1]++;
                }
                if (m2 == "rock") {
                    win[p1-1]++;
                    lose[p2-1]++;
                }
            }

            if (m1 == "scissors") {
                if (m2 == "rock") {
                    win[p2-1]++;
                    lose[p1-1]++;
                }
                if (m2 == "paper") {
                    win[p1-1]++;
                    lose[p2-1]++;
                }
            }
        }

        for (int n = 0; n < N; n++) {
            if ((win[n] + lose[n]) == 0)
                cout << "-" << endl;
            else
                cout << setprecision(3) << fixed << double(win[n])/(win[n] + lose[n]) << endl;
        }
        cout << endl;
    }
    return 0;
}