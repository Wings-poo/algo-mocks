/*
Aug 22 2020 Mock
p394
Mapmaker
v2 - with map/classes; original submission
*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    // input
    int N, R;
    cin >> N >> R;

    map <string, int> dim;
    map <string, int> addr;
    int C[N][10];
    for (int n = 0; n < N; n++) {
        string A;
        cin >> A;

        addr[A] = addr.size();

        int B, bytesize, D;
        cin >> B >> bytesize >> D;
        dim[A] = D;
        int L[10], U[10];
        int l, u;
        for (int d = 1; d <= D; d++) {
            cin >> l >> u;
            L[d] = l;
            U[d] = u;
        }

        C[n][D] = bytesize;
        for (int d = D-1; d > 0; d--) {
            C[n][d] = C[n][d+1]*(U[d+1] - L[d+1] + 1);
        }
        
        C[n][0] = B;
        for (int d = 1; d <= D; d++) {
            C[n][0] -= C[n][d]*L[d];
        }

    }

    // do smth + output
    for (int r = 0; r < R; r++) {
        string A;
        cin >> A;

        cout << A << '[';
        int add = addr[A], idx;
        int answer = C[add][0];
        for (int d = 1; d <= dim[A]; d++) {
            cin >> idx;
            cout << idx;
            if (d < dim[A])
                cout << ", ";
            
            answer += C[add][d]*idx;
        }
        cout << "] = ";

        cout << answer << endl;
    }
    
}