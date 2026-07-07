/*
*OpenKattis
*nineknights
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dx[] = {-1,-1,1,1,-2,-2,2,2};
    int dy[] = {-2,2,-2,2,-1,1,-1,1};

    char grid[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> grid[i][j];
    
    bool valid = true;
    int knights = 0;
    for (int i = 0; (i < 5) && valid; i++)
        for (int j = 0; (j < 5) && valid; j++) {
            if (grid[i][j] == '.')
                continue;

            knights++;

            for (int k = 0; (k < 8) && valid; k++) {
                if (((i + dx[k]) >= 0) && ((i + dx[k]) < 5) && ((j + dy[k]) >= 0) && ((j + dy[k]) < 5))
                    if (grid[i + dx[k]][j + dy[k]] == 'k')
                        valid = false;
            }
        }

    if (valid && (knights == 9))
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
    
    return 0;
}