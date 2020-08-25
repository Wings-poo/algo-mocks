/*
Aug 22 2020 Mock
p483
Word Scramble
v3 - with functions; cleaner version 
*/
#include<bits/stdc++.h>
using namespace std;

void prints (string s)
{
    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i];
    return;
}

int main ()
{
    char c = 'a';
    string s;
    while (c != EOF) {
        c = getchar();
        if ((c != ' ') && (c != '\n')) {
            s.push_back(c);
        } else {
            prints(s);
            s.clear();
            
            if (c == ' ')
                cout << ' ';
            else // (c == '\n')
                cout << '\n';
        } 
    }
}