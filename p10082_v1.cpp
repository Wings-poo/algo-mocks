/*
Aug 22 2020 Mock
p10082
WERTYU
v1 - no classes
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    char c;
    while (1) {
        c = getchar();
        if (c == EOF)
            break;
        
        if ((c != ' ') && (c != '\n')) {
            switch (c) {
                case '1':
                    cout << '`';
                    break; // don't forget!
                case '2':
                    cout << '1';
                    break; // don't forget!
                case '3':
                    cout << '2';
                    break; // don't forget!
                case '4':
                    cout << '3';
                    break; // don't forget!
                case '5':
                    cout << '4';
                    break; // don't forget!
                case '6':
                    cout << '5';
                    break; // don't forget! #copy-paste lol

                /*
                and so on and so forth...
                anyone with a solution that's not as hassle as this?
                and doesn't use classes [map]?
                */

            }
        } else
            cout << c;
    }
}