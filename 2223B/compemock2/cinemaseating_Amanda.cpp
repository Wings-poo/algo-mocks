/*
*OpenKattis
*cinemaseating
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main ()
{
    int R, C, N;
    cin >> R >> C >> N;

    char seating[R+2][C+2];
    for (int r = 0; r < R+2; r++)
        for (int c = 0; c < C+2; c++)
            seating[r][c] = '.';

    for (int n = 0; n < N; n++) {
        int r, c;
        cin >> r >> c;
        seating[r][c] = 'x';
    }

    int ans[9] = {0};
    for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++) {
            if (seating[r][c] == 'x') {
                int neighbors = 0;
                for (int i = 0; i < 8; i++) {
                    if (seating[r+dx[i]][c+dy[i]] == 'x')
                        neighbors++;
                }
                ans[neighbors]++;
            }
        } 

    for (int i = 0; i < 9; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}