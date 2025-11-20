/*
*OpenKattis
*goodmessages
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int O, N;
    string message;
    cin >> O >> message >> N;

    int good = 0, bad = 0;
    for (int n = 0; n < N; n++) {
        for (int i = 0; i < (int) message.size(); i++) {
            int newletter = (message[i] - 'a' + O)%26;
            message[i] = 'a' + newletter;
        }

        int vowel = 0, consonant = 0;
        for (int i = 0; i < (int) message.size(); i++) {
            if ((message[i] == 'a') || (message[i] == 'e') || (message[i] == 'i') || (message[i] == 'o') || (message[i] == 'u') || (message[i] == 'y'))
                vowel++;
            else
                consonant++;
        }

        if (vowel < ceil(consonant/2.))
            good++;
        else
            bad++;
    }

    if (good > bad)
        cout << "Boris" << endl;
    else
        cout << "Colleague" << endl;
    return 0;
}