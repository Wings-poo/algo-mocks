/*
*OpenKattis
*gridmagic
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

//bool not_primes[100000000] = {false};
set <long long> superprimes = {2, 3, 5, 7, 23, 29, 31, 37, 53, 59, 71, 73, 79,
233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797, 
2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393,  
23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939, 
233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399, 
2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933, 
23399339, 29399999, 37337999, 59393339, 73939133};
vector <vector <long long>> superprimes_per_length = {{}, {2, 3, 5, 7}, {23, 29, 31, 37, 53, 59, 71, 73, 79},
{233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797}, 
{2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393},  
{23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939}, 
{233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399}, 
{2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933}, 
{23399339, 29399999, 37337999, 59393339, 73939133}};
int N, M;
int ans = 0;

void backtracking (int grid[][9], int m)
{
    if (m == M) {
        ans++;
        return;
    }

    for (int i = 0; i < (int) superprimes_per_length[N].size(); i++) {
        long long num = superprimes_per_length[N][i];
        for (int j = N - 1; j >= 0; j--) {
            grid[m][j] = num%10;
            num /= 10;
        }

        bool valid = true;
        for (int k = 0; k < N; k++) {
            num = 0;
            for (int l = 0; l <= m; l++) {
                num *= 10;
                num += grid[l][k];
                if (superprimes.find(num) == superprimes.end())
                    valid = false;
            }
        }

        if (valid)
            backtracking(grid, m+1);
    }
}

int main ()
{
    /*
    // hehehe, pre-processing
    not_primes[0] = true;
    not_primes[1] = true;
    for (long long i = 2; i < 100000000; i++) {
        if (not_primes[i] == true)
            continue;
        
        for (int j = 2; i*j < 100000000; j++)
            not_primes[i*j] = true;
        
        bool valid = true;
        int digits = 1;
        int N = i;
        while (N/10) {
            digits++;
            N /= 10;
            if (not_primes[N] == true)
                valid = false;
        }

        if (!valid)
            continue;

        superprimes_per_length[digits].push_back(i);
    }

    for (int i = 1; i < 9; i++) {
        cout << i << endl;
        cout << '{';
        for (int j = 0; j < (int) superprimes_per_length[i].size(); j++)
            cout << superprimes_per_length[i][j] << ", ";
        cout << '}' << endl;
    }
    */

    cin >> N >> M;

    int grid[9][9];
    backtracking(grid, 0);
    
    cout << ans << endl;
    return 0;
}