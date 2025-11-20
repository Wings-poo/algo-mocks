/*
*OnlineJudge
*543 - Goldbach’s Conjecture
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    bool not_primes[1000000] = {false};
    vector <int> primes;
    not_primes[0] = true;
    not_primes[1] = true;
    for (int i = 2; i < 1000000; i++) {
        if (not_primes[i] == true)
            continue;
        
        primes.push_back(i);
        for (int j = 2; i*j < 1000000; j++)
            not_primes[i*j] = true;
    }

    int num;
    while (cin >> num) {
        if (!num)
            break;
        
        bool valid = false;
        for (int i = 1; primes[i] <= num/2; i++) { // do not include 2
            int diff = num - primes[i];
            if (binary_search(primes.begin(), primes.end(), diff)) {
                cout << num << " = " << primes[i] << " + " << diff << endl;
                valid = true;
                break;
            }
        }

        if (!valid)
            cout << "Goldbach's conjecture is wrong." << endl;
    }
    return 0;
}