/*
*OnlineJudge
*111 - History Grading
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;
    while (1) {
        if (cin.peek() == EOF)
            break;

        // correct chronological sequence
        int rank[N];
        for (int n = 0; n < N; n++) {
            int x;
            cin >> x;
            rank[n] = x;
        }

        while (1) {
            if (cin.peek() == EOF)
                break;
            int R;
            cin >> R;
            if (cin.peek() == '\n') {
                N = R;
                break;
            }

            // responses
            int resp[N];
            resp[R-1] = 1;
            for (int n = 2; n <= N; n++) {
                int x;
                cin >> x;
                resp[x-1] = n;
            }

            int arr[N];
            for (int n = 0; n < N; n++) 
                arr[n] = rank[resp[n]-1];

            for (int n = 0; n < N; n++) 
                cout << rank[n] << " ";
            cout << endl;
            for (int n = 0; n < N; n++) 
                cout << resp[n] << " ";
            cout << endl;
            for (int n = 0; n < N; n++) 
                cout << arr[n] << " ";
            cout << endl;

            int ans = 0;
            int lis[N];
            lis[0] = 1;
            for (int i = 1; i < N; i++) {
                lis[i] = 1;
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j])
                        lis[i] = max(lis[i], lis[j] + 1);
                }
                ans = max(ans, lis[i]);
            }

            cout << ans << endl;
        }
    }
    return 0;
}