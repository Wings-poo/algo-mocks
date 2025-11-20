/*
*OpenKattis
*asciifigurerotation
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    bool first = true;
    while (1) {
        cin >> N;
        if (!N)
            break;
        getchar();

        if (first)
            first = false;
        else
            cout << endl;
        
        char asciifigure[100][N] = {0};
        int maxcolumn = 0;
        for (int n = 0; n < N; n++) {
            string line;
            getline(cin, line);

            int len = line.size();
            maxcolumn = max(maxcolumn, len);

            for (int i = 0; i < len; i++) {
                asciifigure[i][n] = line[i];
            }
        }

        vector <string> newfigure (maxcolumn);
        for (int i = 0; i < maxcolumn; i++) {
            for (int n = N-1; n >= 0; n--) {
                if ((asciifigure[i][n] != ' ') && (asciifigure[i][n] != '+') && (asciifigure[i][n] != '-') && (asciifigure[i][n] != '|'))
                    newfigure[i].push_back(' ');//cout << " ";
                else if (asciifigure[i][n] == '-')
                    newfigure[i].push_back('|');//cout << "|";
                else if (asciifigure[i][n] == '|')
                    newfigure[i].push_back('-');//cout << "-";
                else
                    newfigure[i].push_back(asciifigure[i][n]);//cout << asciifigure[i][n];

            }
        }

        for (int i = 0; i < maxcolumn; i++) {
            int maxj = 0;
            for (int j = 0; j < N; j++) {
                if (newfigure[i][j] != ' ')
                    maxj = j;
            }    
            for (int j = 0; j <= maxj; j++) {
                cout << newfigure[i][j];
            }  
            cout << endl;           
        }
        
    }
    return 0;
}