/*
*OpenKattis
*selfsimilarstrings
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string S;
    while (cin >> S) {
        int D = 0;
        for (int d = 1; d < (int) S.size(); d++) {
            set <string> substrs;
            set <string> repeats;
            for (int s_idx = 0, e_idx = s_idx + d; e_idx < (int) S.size() + 1; s_idx++, e_idx = s_idx + d) { 
                string s = S.substr(s_idx, d);
                if (substrs.find(s) != substrs.end()) {
                    repeats.insert(s);
                }
                substrs.insert(s);
            }

            if (repeats.size() == substrs.size())
                D = d;
        }
        cout << D << endl;
    }
    return 0;
}