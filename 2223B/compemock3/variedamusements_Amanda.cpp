// Partial only
/*
*OpenKattis
*variedamusements
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long ans = 0;
void func (long long n, long long a, long long b, long long c, long long m, long long prev, long long mult)
{
    if (m == n) {
        ans += mult%mod;
        ans %= mod;
        return;
    }
    
    if (prev != 1) 
        func(n,a,b,c,m+1,1,(mult*a)%mod);
    if (prev != 2)
        func(n,a,b,c,m+1,2,(mult*b)%mod);
    if (prev != 3)
        func(n,a,b,c,m+1,3,(mult*c)%mod);
    
    return;
}

int main ()
{
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    func(n,a,b,c,0,0,1);
    cout << ans%mod << endl;
    return 0;
}