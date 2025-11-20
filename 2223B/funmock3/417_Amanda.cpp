/*
*OnlineJudge
*417 - Word Index
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    // brute-force, let's go :joy:
    map <string, int> idx;
    int index = 1;

    for (char c  = 'a'; c <= 'z'; c++) {
        string str;
        str.push_back(c);
        idx[str] = index;
        index++;
    }

    for (char c  = 'a'; c <= 'z'; c++) {
        string str;
        str.push_back(c);
        for (char d = c + 1; d <= 'z'; d++) {
            str.push_back(d);
            idx[str] = index;
            index++;
            str.pop_back();
        }
        str.pop_back();
    }

    for (char c  = 'a'; c <= 'z'; c++) {
        string str;
        str.push_back(c);
        for (char d = c + 1; d <= 'z'; d++) {
            str.push_back(d);
            for (char e = d + 1; e <= 'z'; e++) {
                str.push_back(e);
                idx[str] = index;
                index++;
                str.pop_back();
            }
            str.pop_back();
        }
        str.pop_back();
    }

    for (char c  = 'a'; c <= 'z'; c++) {
        string str;
        str.push_back(c);
        for (char d = c + 1; d <= 'z'; d++) {
            str.push_back(d);
            for (char e = d + 1; e <= 'z'; e++) {
                str.push_back(e);
                for (char f = e + 1; f <= 'z'; f++) {
                    str.push_back(f);
                    idx[str] = index;
                    index++;
                    str.pop_back();
                }
                str.pop_back();
            }
            str.pop_back();
        }
        str.pop_back();
    }

    for (char c  = 'a'; c <= 'z'; c++) {
        string str;
        str.push_back(c);
        for (char d = c + 1; d <= 'z'; d++) {
            str.push_back(d);
            for (char e = d + 1; e <= 'z'; e++) {
                str.push_back(e);
                for (char f = e + 1; f <= 'z'; f++) {
                    str.push_back(f);
                    for (char g = f + 1; g <= 'z'; g++) {
                        str.push_back(g);
                        idx[str] = index;
                        index++;
                        str.pop_back();
                    }
                    str.pop_back();
                }
                str.pop_back();
            }
            str.pop_back();
        }
        str.pop_back();
    }

    string str;
    while (cin >> str)
        cout << idx[str] << endl;
    return 0;
}