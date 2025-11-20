/*
*Hackerrank - National Olympiad in Informatics - Philippines 2014 Finals
*questions-i-ask-myself
*Code by: Amanda Lim
*/

// not complete

#include <bits/stdc++.h>
using namespace std;

vector <int> primes;
void get_primes()
{
    bool not_prime[1000000] = {false};
    for (int i = 2; i < 1000000; i++) {
        if (not_prime)
            continue;
        primes.push_back(i);
        for (int j = 2; i*j < 1000000; j++)
            not_prime[i*j] = true;
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    get_primes();
    

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        string ope;
        int A, B, M, V;
        
        cin >> ope;
        if (ope == "ADD")
            cin >> V;
        else
            cin >> A >> B >> M;
    }
    
    return 0;
}