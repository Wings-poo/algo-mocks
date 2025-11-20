/*
*OpenKattis
*primaryarithmetic
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int A, B;
    while (cin >> A >> B) {
        if (!A && !B)
            break;
        
        int carry_ope = 0, carry = 0;
        while (A || B) {
            int a = A % 10, b = B % 10;
            if ((a + b + carry) >= 10)
                carry_ope++;

            A /= 10;
            B /= 10;
            carry = (a + b + carry)/10;
        }

        if (carry_ope == 0)
            cout << "No carry operation." << endl;
        else if (carry_ope == 1)
            cout << "1 carry operation." << endl;
        else
            cout << carry_ope << " carry operations." << endl;
    }
    return 0;
}