/*
*OpenKattis
*increasingsubsequence
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int GetCeilIndex(int arr[], vector<int>& T, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    while (cin >> N) {
        if (!N)
            break;

        int arr[N];
        for (int n = 0; n < N; n++)
            cin >> arr[n];

        vector<int> tailIndices(N, 0); // Initialized with 0
        vector<int> prevIndices(N, -1); // initialized with -1
 
        int len = 1; // it will always point to empty location
        for (int i = 1; i < N; i++) {
            if (arr[i] < arr[tailIndices[0]]) {
                // new smallest value
                tailIndices[0] = i;
            }
            else if (arr[i] > arr[tailIndices[len - 1]]) {
                // arr[i] wants to extend largest subsequence
                prevIndices[i] = tailIndices[len - 1];
                tailIndices[len++] = i;
            }
            else {
                // arr[i] wants to be a potential condidate of
                // future subsequence
                // It will replace ceil value in tailIndices
                int pos = GetCeilIndex(arr, tailIndices, -1,
                                    len - 1, arr[i]);
    
                prevIndices[i] = tailIndices[pos - 1];
                tailIndices[pos] = i;
            }
        }

        int maxLIS[len];
        for (int i = tailIndices[len - 1], idx = len - 1; i >= 0; i = prevIndices[i], idx--)
            maxLIS[idx] = arr[i];

        cout << len;
        for (int i = 0; i < len; i++)
            cout << " " << maxLIS[i];
        cout << endl;
        
    }    
    
    return 0;
}