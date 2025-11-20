/*
*OpenKattis
*bigintegers
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string A, B;
        cin >> A >> B;

        bool Nick_first_smaller = false;
        if (A < B)
            Nick_first_smaller = true;

        bool real_first_smaller = false;

        /*
        // brute-force computation of the integer equivalent
        long long A_int = 0, B_int = 0;
        for (int a_idx = A.length() - 1, a_pow = 0; a_idx >= 0 ; a_idx--, a_pow++)
            A_int += isdigit(A[a_idx]) ? ((A[a_idx] - '0') * pow(62, a_pow)) : (A[a_idx] <= 'Z') ? (((A[a_idx] - 'A') + 36) * pow(62, a_pow)) : (((A[a_idx] - 'a') + 10) * pow(62, a_pow));
        for (int b_idx = B.length() - 1, b_pow = 0; b_idx >= 0 ; b_idx--, b_pow++)
            B_int += isdigit(B[b_idx]) ? ((B[b_idx] - '0') * pow(62, b_pow)) : (B[b_idx] <= 'Z') ? (((B[b_idx] - 'A') + 36) * pow(62, b_pow)) : (((B[b_idx] - 'a') + 10) * pow(62, b_pow));
        if (A_int < B_int)
            real_first_smaller = true;
        */

        if (A.length() < B.length())
            real_first_smaller = true;
        else {
            for (int idx = 0; idx < int(A.length()); idx++) {
                int A_val = A[idx], B_val = B[idx];

                if (isupper(A[idx]))
                    A_val = tolower(A[idx]);
                else if (islower(A[idx]))
                    A_val = toupper(A[idx]);

                if (isupper(B[idx]))
                    B_val = tolower(B[idx]);
                else if (islower(B[idx]))
                    B_val = toupper(B[idx]);

                if (A_val < B_val) {
                    real_first_smaller = true;
                    break;
                } else if (A_val > B_val) {
                    real_first_smaller = false;
                    break;
                } else
                    continue;
            }
        }
        
        if ((Nick_first_smaller == real_first_smaller) || (A == B))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}