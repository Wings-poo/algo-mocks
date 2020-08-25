/*
Aug 22 2020 Mock
p10082
WERTYU
v2 - with classes; original submission
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string mej ="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; // couldn't think of a proper variable name that time, sorry
    map <char, int> idx;
    for (int i = 0; i < mej.size(); i++) 
        idx[mej[i]] = i;
    
    char c;
    while (1) {
        c = getchar();
        if (c == EOF)
            break;
        
        if ((c != ' ') && (c != '\n')) {
            int i = idx[c]; // lol, yes it could be idx[c] - 1; was just panicking
            i--;
            cout << mej[i]; // or it could be cout << mej[idx[c] - 1];
        } else
            cout << c;
    }
}