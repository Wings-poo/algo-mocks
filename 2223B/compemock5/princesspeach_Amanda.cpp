/*
*OpenKattis
*princesspeach
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N, Y;
    cin >> N >> Y;

    set <int> obstacles;
    for (int y = 0; y < Y; y++) {
        int k;
        cin >> k;
        obstacles.insert(k);
    }

    for (int n = 0; n < N; n++) {
        if (obstacles.find(n) == obstacles.end())
            cout << n << endl;
    }

    cout << "Mario got " << obstacles.size() << " of the dangerous obstacles." << endl;
    return 0;
}