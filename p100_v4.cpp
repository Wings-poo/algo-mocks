/*
Aug 22 2020 Mock
p100
The 3n+1 problem
v4 - with recursion
*/
#include<bits/stdc++.h>
using namespace std;

int cylen (int n) {
    if (n == 1)
        return 1;
    
    if (n%2)
        return 1 + cylen((3*n) + 1);
    else
        return 1 + cylen(n/2);
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