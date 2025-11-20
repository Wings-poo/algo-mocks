/*
*Hackerrank - National Olympiad in Informatics - Philippines 2014 Finals
*xoxo
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    char grid[N][M];
    int X = 0, O = 0;
    for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++) {
            cin >> grid[n][m];
            if (grid[n][m] == 'X')
                X++;
            else
                O++;
        }

    if ((X != (O + 1)) && (X != O))
        cout << "INVALID" << endl;
    else {
        X = 0;
        O = 0;
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (n <= (N - 4)) {
                    if ((grid[n][m] == 'X') && (grid[n+1][m] == 'X') && (grid[n+2][m] == 'X') && (grid[n+3][m] == 'X'))
                        X++;
                    if ((grid[n][m] == 'O') && (grid[n+1][m] == 'O') && (grid[n+2][m] == 'O') && (grid[n+3][m] == 'O'))
                        O++;
                }
                if (m <= (M - 4)) {
                    if ((grid[n][m] == 'X') && (grid[n][m+1] == 'X') && (grid[n][m+2] == 'X') && (grid[n][m+3] == 'X'))
                        X++;
                    if ((grid[n][m] == 'O') && (grid[n][m+1] == 'O') && (grid[n][m+2] == 'O') && (grid[n][m+3] == 'O'))
                        O++;
                }
                if ((n <= (N - 4)) && (m <= (M - 4))) {
                    if ((grid[n][m] == 'X') && (grid[n+1][m+1] == 'X') && (grid[n+2][m+2] == 'X') && (grid[n+3][m+3] == 'X'))
                        X++;
                    if ((grid[n][m] == 'O') && (grid[n+1][m+1] == 'O') && (grid[n+2][m+2] == 'O') && (grid[n+3][m+3] == 'O'))
                        O++;
                }
                if ((n <= (N - 4)) && ((m - 3) >= 0)) {
                    if ((grid[n][m] == 'X') && (grid[n+1][m-1] == 'X') && (grid[n+2][m-2] == 'X') && (grid[n+3][m-3] == 'X'))
                        X++;
                    if ((grid[n][m] == 'O') && (grid[n+1][m-1] == 'O') && (grid[n+2][m-2] == 'O') && (grid[n+3][m-3] == 'O'))
                        O++;
                }
            }
        }

        if (X == O)
            cout << "BOTH PLAYERS ARE TIED AT " << X << " POINT(S)" << endl;
        else if (X > O)
            cout << "X WINS BY " << X - O << " POINT(S)" << endl;
        else
            cout << "O WINS BY " << O - X << " POINT(S)" << endl;
    }
    return 0;
}