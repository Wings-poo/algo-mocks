/*
Aug 22 2020 Mock
p483
Word Scramble
v2 - with functions; original submission
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
        if (c == ' ') {
            prints(s);
            cout << ' ';
            s.clear();
        } else if (c == '\n') {
            prints(s);
            cout << '\n';
            s.clear();
        } else
            s.push_back(c);
    }
}