/*
Aug 22 2020 Mock
p100
The 3n+1 problem
v2 - with functions; original submission
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
        for (int x = i; x <= j; x++) {
            int n = x;
            int cylen = 1;

            while (n != 1) {
                cylen++;
                if (n%2)
                    n = (3*n) + 1;
                else
                    n /= 2;
            }

            maxcy = max(cylen,maxcy);
        }

        cout << maxcy << endl;
    }
}