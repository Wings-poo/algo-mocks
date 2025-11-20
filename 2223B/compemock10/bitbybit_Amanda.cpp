/*
*OpenKattis
*bitbybit
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    while (cin >> N) {
        if (!N)
            break;

        vector <int> binary (32, -1);

        for (int n = 0; n < N; n++) {
            string cmd;
            cin >> cmd;

            int i, j;
            if (cmd == "CLEAR") {
                cin >> i;
                binary[i] = 0;
            }
            
            if (cmd == "SET") {
                cin >> i;
                binary[i] = 1;
            }

            if (cmd == "OR") {
                cin >> i >> j;
                if ((binary[i] == 1) || (binary[j] == 1))
                    binary[i] = 1;
                else if ((binary[i] == -1) || (binary[j] == -1))
                    binary[i] = -1;
                else
                    binary[i] = 0;
            }

            if (cmd == "AND") {
                cin >> i >> j;
                if ((binary[i] == 1) && (binary[j] == 1))
                    binary[i] = 1;
                else if ((binary[i] == 0) || (binary[j] == 0))
                    binary[i] = 0;
                else
                    binary[i] = -1;
            }
        }

        for (int n = 31; n >= 0; n--) {
            if (binary[n] == -1)
                cout << '?';
            else
                cout << binary[n];
        }

        cout << endl;
    }
    return 0;
}