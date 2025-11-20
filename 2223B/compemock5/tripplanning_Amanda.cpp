/*
*OpenKattis
*tripplanning
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N, M;
    cin >> N >> M;

    map <pair <int, int>, int> TL;
    int TLnum = 1;
    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a,b);
        TL[make_pair(a,b)] = TLnum;
        TLnum++;
    }

    bool valid = true;
    vector <int> TLorder;
    for (int i = 1; i <= N - 1; i++) {
        if (TL.find(make_pair(i, i+1)) == TL.end()) {
            valid = false;
            break;
        } else
            TLorder.push_back(TL[make_pair(i, i+1)]);
    }

    if (TL.find(make_pair(1, N)) == TL.end()) {
            valid = false;
    } else
        TLorder.push_back(TL[make_pair(1, N)]);   
    
    if (valid) {
        for (int i = 0; i < (int) TLorder.size(); i++)
            cout << TLorder[i] << endl;
    } else
        cout << "impossible" << endl;
    return 0;
}