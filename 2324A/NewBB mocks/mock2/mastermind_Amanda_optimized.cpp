/*
*OpenKattis
*mastermind
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// straightforward
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    int alphabetA[26] = {0}, alphabetB[26] = {0};
    string A, B;
    cin >> A >> B;

    int r = 0, s = 0;
    for (int n = 0; n < N; n++) {
        if (A[n] == B[n])
            r++;
        else {
            alphabetA[A[n] - 'A']++;
            alphabetB[B[n] - 'A']++;
        }
    }

    for (int n = 0; n < 26; n++)
        s += min(alphabetA[n], alphabetB[n]);

    cout << r << " " << s << endl;
    return 0;
}