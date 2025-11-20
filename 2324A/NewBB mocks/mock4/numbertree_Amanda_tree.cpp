/*
*OpenKattis
*numbertree
*Code by: Amanda Lim
*/

// MLE

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int H;
    cin >> H;

    int N = pow(2,H + 1) - 1;

    int tree[N];
    for (int i = 0; i < N; i++)
        tree[i] = N - i;

    string S;
    cin >> S;

    int idx = 0;
    for (auto i: S) {
        if (i == 'L')
            idx = 2*idx + 1;
        else
            idx = 2*idx + 2;
    }

    cout << tree[idx] << endl;

    return 0;
}