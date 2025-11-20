/*
*OnlineJudge
*12049 - Just Prune The List
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;

        vector <int> listN (N);
        for (int n = 0; n < N; n++)
            cin >> listN[n];
        
        vector <int> listM (M);
        for (int m = 0; m < M; m++)
            cin >> listM[m];
        
        sort(listN.begin(), listN.end());
        sort(listM.begin(), listM.end());

        int sz = max(N, M);
        vector <int> intersection (sz);
        auto it = set_intersection(listN.begin(), listN.end(), listM.begin(), listM.end(), intersection.begin());
        intersection.resize(it - intersection.begin());

        cout << (listN.size() - intersection.size()) + (listM.size() - intersection.size()) << endl;
    }
    return 0;
}