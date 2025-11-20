/*
*OpenKattis
*compoundwords
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <string> words (100);
    int N = 0;

    while (cin.peek() != EOF) {
        string word;
        cin >> word;
        words[N++] = word;
    }

    set <string> compoundwords;
    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N-1; j++) {
            compoundwords.insert(words[i] + words[j]);
            compoundwords.insert(words[j] + words[i]);
        }

    for (auto word : compoundwords)
        cout << word << endl;

    return 0;
}