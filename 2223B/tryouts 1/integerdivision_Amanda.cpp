/*
*OpenKattis
*integerdivision
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

long long fact (int N)
{
    if (N < 2)
        return 0;

    long long retval = 1;
    for (int n = N - 1; n <= N; n++) 
        retval *= n;
    
    return retval;
}

int main ()
{
    int N, d;
    cin >> N >> d;

    int a[N];
    for (int n = 0; n < N; n++)
        cin >> a[n];
    
    sort(a, a + N);

    long long prev_quotient = -1, curr_quotient = -1;
    long long ans = 0, same = 1;
    for (int n = 0; n < N; n++) {
        prev_quotient = curr_quotient;
        curr_quotient = a[n]/d;

        if (prev_quotient == curr_quotient)
            same++;
        else {
            ans += fact(same)/2;
            same = 1;
        }
    }

    ans += fact(same)/2;

    cout << ans << endl;
    return 0;
}