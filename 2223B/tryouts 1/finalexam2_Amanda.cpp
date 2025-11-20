/*
*OpenKattis
*finalexam2
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    int correct = 0;
    char curr = ' ', prev = ' ';
    for (int n = 0; n < N; n++) {
        prev = curr;
        cin >> curr;

        if (prev == curr)
            correct++;        
    }

    cout << correct << endl;
    return 0;
}