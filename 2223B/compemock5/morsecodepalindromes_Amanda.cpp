/*
*OpenKattis
*morsecodepalindromes
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    map <char, string> morse;
    morse['A'] = ".-"; 
    morse['B'] = "-...";
    morse['C'] = "-.-.";
    morse['D'] = "-..";
    morse['E'] = ".";
    morse['F'] = "..-.";
    morse['G'] = "--.";
    morse['H'] = "....";
    morse['I'] = "..";
    morse['J'] = ".---";
    morse['K'] = "-.-";
    morse['L'] = ".-..";
    morse['M'] = "--";
    morse['N'] = "-.";
    morse['O'] = "---";
    morse['P'] = ".--.";
    morse['Q'] = "--.-";
    morse['R'] = ".-.";
    morse['S'] = "...";
    morse['T'] = "-";
    morse['U'] = "..-";
    morse['V'] = "...-";
    morse['W'] = ".--";
    morse['X'] = "-..-";
    morse['Y'] = "-.--";
    morse['Z'] = "--..";
    morse['0'] = "-----";
    morse['1'] = ".----";
    morse['2'] = "..---";
    morse['3'] = "...--";
    morse['4'] = "....-";
    morse['5'] = ".....";
    morse['6'] = "-....";
    morse['7'] = "--...";
    morse['8'] = "---..";
    morse['9'] = "----.";

    string message;
    getline(cin, message);

    string morse_message;
    for (int i = 0; i < (int) message.size(); i++) {
        if (isalnum(message[i]))
            morse_message += morse[toupper(message[i])];
    }

    if (morse_message.empty())
        cout << 0 << endl;
    else {
        bool palindrome = true;
        for (int i = 0, j = (int) morse_message.size() - 1; i < j; i++, j--) {
            if (morse_message[i] != morse_message[j])
                palindrome = false;
        }

        cout << palindrome << endl;
    }
    return 0;
}