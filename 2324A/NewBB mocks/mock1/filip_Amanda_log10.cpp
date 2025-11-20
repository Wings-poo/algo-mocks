/*
*OpenKattis
*filip
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int flip (int N)
{
    int newN = 0;
    int power = log10(N);

    while (N) {
        newN += (N%10 * pow(10, power));
        N /= 10;
        power--;
    }

    return newN;
}
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int A, B;
    cin >> A >> B;
    cout << max(flip(A), flip(B));
    
    return 0;
}