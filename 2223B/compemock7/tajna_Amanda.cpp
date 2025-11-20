/*
*OpenKattis
*tajna
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string encoded;
    cin >> encoded;

    int len = encoded.size();
    int R = -1, C = -1;
    for (int i = 1; i < sqrt(len) + 1; i++) {
        if (len%i == 0) {
            if (R == -1) {
                R = min(len/i, i);
                C = max(len/i, i);
            } else {
                int r = min(len/i, i);
                int c = max(len/i, i);
                if (r > R) {
                    R = r;
                    C = c;
                }
            }
        }
    }

    for (int i = 0; i < len/C; i++) {
        for (int j = i; j < len; j += R) {
            cout << encoded[j];
        }
    }

    return 0;
}