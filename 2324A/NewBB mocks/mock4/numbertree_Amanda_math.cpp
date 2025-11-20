/*
*OpenKattis
*numbertree
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int H;
    cin >> H;

    int N = pow(2, H + 1) - 1;
    int pow2 = 0;

    string S;
    cin >> S;

    int sub = 1;
    for (int i = 0; i < (int) S.size(); i++) {
        sub *= 2;
        if (S[i] == 'R')
            sub++;
    }

    cout << N - (sub - 1) << endl;

    return 0;
}