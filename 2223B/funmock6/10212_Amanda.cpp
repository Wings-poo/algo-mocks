/*
*OnlineJudge
*10212 - The Last Non-zero Digit
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long N, M;
    while (cin >> N >> M) {
        long long ans = 1;
        for (long long i = N; i >= N - M + 1; i--) {
            ans *= i;

            while (ans%10 == 0) // to avoid overflow + remove unneeded zeroes
                ans /= 10;
            
            ans %= 1000000000; // to avoid overflow
        }
        cout << ans%10 << endl; // get last nonzero digit
    }
    return 0;
}