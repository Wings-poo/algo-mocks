/*
*OpenKattis
*mrcodeformatgrader
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

string int2string (int i)
{
    i++; // index starts at 1
    string s = "";
    while (i/10) {
        int mod = i%10;
        s.push_back(mod + '0');
        i /= 10;
    }
    s.push_back(i + '0');
    reverse(s.begin(), s.end());
    return s;
}

int main ()
{
    int C, N;
    cin >> C >> N;

    int error[C+1] = {0};
    error[C] = -1;
    for (int n = 0; n < N; n++) {
        int i;
        cin >> i;
        error[i-1] = 1;
    }

    int prev_idx = 0;
    int prev = error[0];
    vector <string> errors;
    vector <string> correct;
    for (int c = 0; c <= C; c++) {
        if (error[c] != prev) {
            if (prev_idx == c - 1) {
                string pushme = "";
                pushme += int2string(prev_idx);
                if (prev)
                    errors.push_back(pushme);
                else
                    correct.push_back(pushme);
            } else {
                string pushme = "";
                pushme += int2string(prev_idx);
                pushme += "-";
                pushme += int2string(c-1);
                if (prev)
                    errors.push_back(pushme);
                else
                    correct.push_back(pushme);
            }
            prev_idx = c;
            prev = error[c];
        }
    }

    cout << "Errors: " << errors[0];
    for (int i = 1; i < (int) errors.size() - 1; i++)
        cout << ", " << errors[i];
    if (errors.size() > 1)
        cout << " and " << errors[errors.size() - 1];
    cout << endl;

    cout << "Correct: " << correct[0];
    for (int i = 1; i < (int) correct.size() - 1; i++)
        cout << ", " << correct[i];
    if (correct.size() > 1)
        cout << " and " << correct[correct.size() - 1];
    cout << endl;
    return 0;
}