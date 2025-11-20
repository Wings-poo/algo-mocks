/*
*OpenKattis
*shiritori
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    set <string> donewords; // unordered_set for speed
    string pastword = "";
    bool lost = false;
    for (int n = 0; n < N; n++) {
        string word;
        cin >> word;

        if (pastword != "") {
            if (donewords.find(word) != donewords.end()) {
                cout << "Player " << n%2 + 1 << " lost" << endl; // even is p1, odd is p2
                lost = true;
                break;
            }

            if (word[0] != pastword[pastword.size() - 1]) {
                cout << "Player " << n%2 + 1 << " lost" << endl;
                lost = true;
                break;
            }
        }

        donewords.insert(word);
        pastword = word;
    }

    if (!lost)
        cout << "Fair Game" << endl;

    return 0;
}