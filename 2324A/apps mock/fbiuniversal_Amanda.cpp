/*
*OpenKattis
*fbiuniversal
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    map <char, char> confusion = {{'B','8'}, {'G','C'}, {'I','1'}, {'O','0'}, {'Q','0'}, {'S','5'}, {'U','V'}, {'Y','V'}, {'Z','2'}};
    vector <char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'C', 'D', 'E', 'F', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'T', 'V', 'W', 'X'};
    map <char, long long> value;
    for (int i = 0; i < (int) digits.size(); i++)
        value[digits[i]] = i;
    vector <long long> multiplier = {2, 4, 5, 7, 8, 10, 11, 13};

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        long long N;
        cin >> N;

        long long checkdigit = 0, base10 = 0;
        for (int i = 0; i < 8; i++) {
            char c;
            cin >> c;

            if (confusion.find(c) != confusion.end()) {
                c = confusion[c];
            }

            checkdigit += multiplier[i] * value[c];
            base10 += value[c] * pow(27,8-1-i);
        }
        checkdigit %= 27;

        char checkdigit_entered;
        cin >> checkdigit_entered;

        cout << N << " ";
        if (checkdigit != value[checkdigit_entered])
            cout << "Invalid" << endl;
        else
            cout << base10 << endl;
    }
    return 0;
}