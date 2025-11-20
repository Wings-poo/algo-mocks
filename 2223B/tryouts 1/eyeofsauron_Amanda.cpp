/*
*OpenKattis
*eyeofsauron
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int left = 0, right = 0;
    string str;
    
    cin >> str;
    bool leftlines = true;
    for (int n = 0; n < (int) str.size(); n++) {
        if (str[n] == '(')
            continue;
        else if (str[n] == ')')
            leftlines = false;
        else {
            if (leftlines)
                left++;
            else    
                right++;
        }
    }

    if (left == right)
        cout << "correct" << endl;
    else
        cout << "fix" << endl;
    return 0;
}