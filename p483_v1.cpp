/*
Aug 22 2020 Mock
p483
Word Scramble
v1 - no functions
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    char c = 'a';
    string s;
    while (c != EOF) {
        c = getchar();
        if ((c != ' ') && (c != '\n')) {
            s.push_back(c);
        } else {
            for (int i = s.size() - 1; i >= 0; i--)
                cout << s[i];
            s.clear();
            
            if (c == ' ')
                cout << ' ';
            else // (c == '\n')
                cout << '\n';
        } 
    }
}