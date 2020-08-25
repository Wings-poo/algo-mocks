/*
Aug 22 2020 Mock
p100
The 3n+1 problem
v3 - memoization
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    
    int i, j;
    while (cin >> i >> j) { // returns True if it's successful, false otherwise
        cout << i << " " << j << " ";

        if (i > j) // problem does not specify that i < j
            swap(i,j);

        int maxcy = 0;
        int maxcycles[1000000] = {0}; // max array size
        for (int x = i; x <= j; x++) {
            int n = x;
            int cylen = 1;

            while (n != 1) {
                if (n%2)
                    n = (3*n) + 1;
                else
                    n /= 2;
                
                if ((n < 1000000) && (maxcycles[n] != 0)) {
                    cylen += maxcycles[n];
                    break;
                }

                cylen++;
            }

            if (x < 1000000) // scam pota
                maxcycles[x] = cylen;
            
            maxcy = max(cylen,maxcy);
        }

        cout << maxcy << endl;
    }
}