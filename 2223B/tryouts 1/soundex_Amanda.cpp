/*
*OpenKattis
*soundex
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int soundex[] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};

    string word;
    while (cin >> word) {
        int prev_soundex = 0, curr_soundex = 0;
        for (int i = 0; i < (int) word.size(); i++) {
            prev_soundex = curr_soundex;
            curr_soundex = soundex[word[i] - 'A'];

            if ((prev_soundex != curr_soundex) && curr_soundex)
                cout << curr_soundex;
        }
        cout << endl;
    }
    return 0;
}