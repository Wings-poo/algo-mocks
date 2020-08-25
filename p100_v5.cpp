/*
Aug 22 2020 Mock
p100
The 3n+1 problem
v5 - memoization with recursion
*/
#include<bits/stdc++.h>
using namespace std;

int maxcycles[1000000] = {0}; // max array size; global variable

int cylen (int n) {
    int cyclen;

    if (n == 1)
        cyclen = 1;
    else if ((n < 1000000) && (maxcycles[n] != 0)) {
        cyclen = maxcycles[n];
    } else {
        if (n%2)
            cyclen = 1 + cylen((3*n) + 1);
        else
            cyclen = 1 + cylen(n/2);
    }

    if (n < 1000000) // scam pota
        maxcycles[n] = cyclen;
    
    return cyclen;
}

int main ()
{
    
    int i, j;
    while (cin >> i >> j) { // returns True if it's successful, false otherwise
        cout << i << " " << j << " ";

        if (i > j) // problem does not specify that i < j
            swap(i,j);

        int maxcy = 0;
        for (int x = i; x <= j; x++)
            maxcy = max(cylen(x),maxcy);

        cout << maxcy << endl;
    }
}