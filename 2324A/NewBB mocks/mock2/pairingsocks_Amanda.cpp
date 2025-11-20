/*
*OpenKattis
*pairingsocks
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

    queue <int> sockpile;
    for (int n = 0; n < 2*N; n++) {
        int sock;
        cin >> sock;
        sockpile.push(sock);
    }

    stack <int> othersockpile;
    int moves = 0;
    while (!sockpile.empty()) {
        bool taken = false;

        int sock = sockpile.front();
        sockpile.pop();
      
        if (!othersockpile.empty()) {
            if (othersockpile.top() == sock) {
                othersockpile.pop();
                moves++;
                taken = true;
            }
        }

        if (!taken) {
            othersockpile.push(sock);
            moves++;
        }
    }

    if (othersockpile.empty())
        cout << moves << endl;
    else
        cout << "impossible" << endl;

    return 0;
}