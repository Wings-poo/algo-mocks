/*
*CodeForces
*104064 - B. Boredom Buster
*Code by: Amanda Lim
*/

// WA, misunderstood the problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    set <int> card_pairs;
    int cards[N];
    int matched = 0;
    int last_opened = 0;

    while (matched < N/2) {
        cout << "? " << last_opened + 1 << " " << last_opened + 2 << endl;
        
        int a, b;
        cin >> a >> b;
        cards[last_opened] = b;
        cards[last_opened + 1] = a;

        if (card_pairs.find(a) == card_pairs.end())
            card_pairs.insert(a);
        else
            matched++;

        if (card_pairs.find(b) == card_pairs.end())
            card_pairs.insert(b);
        else
            matched++;
    }

    cout << "! ";
    for (int i = 0; i < N; i++)
        cout << cards[i] << " ";
    cout << endl;
    
    return 0;
}