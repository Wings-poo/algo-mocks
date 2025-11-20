/*
*OpenKattis
*wolf
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    if (N > 26) // shuffle cards s.t. all cards don't match suit
        cout << "possible" << endl;
    else if (N < 26) // unsure win because best you could do is shuffle to get center pile then reshuffle your deck
        cout << "impossible" << endl;
    else {
        int rank;
        char suit;

        vector <int> C;
        vector <int> D;
        vector <int> H;
        vector <int> S;

        for (int n = 0; n < N; n++) {
            cin >> rank >> suit;
            if (suit == 'C')
                C.push_back(rank);
            if (suit == 'D')
                D.push_back(rank);
            if (suit == 'H')
                H.push_back(rank);
            if (suit == 'S')
                S.push_back(rank);
        }

        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        sort(H.begin(), H.end());
        sort(S.begin(), S.end());

        bool possible = false;
        for (int i = 1; i <= (int) C.size(); i++)
            if (C[i-1] > i)
                possible = true;
        for (int i = 1; i <= (int) D.size(); i++)
            if (D[i-1] > i)
                possible = true;
        for (int i = 1; i <= (int) H.size(); i++)
            if (H[i-1] > i)
                possible = true;
        for (int i = 1; i <= (int) S.size(); i++)
            if (S[i-1] > i)
                possible = true;
        
        if (possible)
            cout << "possible" << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}