/*
*CodeForces
*104064 - A. Access Denied
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len = 1;
    string guess = "A";
    while (1) {
        cout << guess << endl;
        
        string tapon, cmd;
        char c;
        int time;
        cin >> tapon >> cmd;
        if (cmd == "GRANTED")
            break;
        
        cin >> c >> time >> tapon;
        if (time == 5) { // find length first
            len += 1;
            guess.push_back('A');
        } else {
            time -= (4 + 1 + 1 + 3 + 1); // first if for len, for loop init, return false
            
            int idx = time/9;

            char orig_guess = guess[idx];
            if (isupper(orig_guess) && (orig_guess == 'Z'))
                guess[idx] = 'a';
            else if (islower(orig_guess) && (orig_guess == 'z'))
                guess[idx] = '0';
            else
                guess[idx]++;
        }
    }
    
    return 0;
}