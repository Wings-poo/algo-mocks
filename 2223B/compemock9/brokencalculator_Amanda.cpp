/*
*OpenKattis
*brokencalculator
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    long long c = 1;
    for (int n = 0; n < N; n++) {
        long long a, b;
        char op;
        cin >> a >> op >> b;

        if (op == '+')
            c = (a + b) - c;
        if (op == '-')
            c = (a - b) * c;
        if (op == '*')
            c = (a * b) * (a * b);
        if (op == '/')
            c = ceil(a / 2.0);
        
        cout << c << endl;
    }
    return 0;
}