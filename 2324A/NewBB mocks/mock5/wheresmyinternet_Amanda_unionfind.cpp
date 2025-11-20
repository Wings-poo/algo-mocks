/*
*OpenKattis
*wheresmyinternet
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int find (int parent[], int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent, parent[x]);
}

void connect (int parent[], int saizu[], int a, int b)
{
    int roota = find(parent, a);
    int rootb = find(parent, b);

    if (saizu[roota] < saizu[rootb])
        swap(roota, rootb);

    parent[rootb] = roota;
    saizu[roota] += saizu[rootb];
    saizu[rootb] = 0;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    int parent[N], saizu[N];
    for (int n = 0; n < N; n++) {
        parent[n] = n;
        saizu[n] = 1;
    }

    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;
        connect(parent, saizu, a - 1, b - 1);
    }

    bool valid = true;
    int parent0 = find(parent,0);
    for (int n = 0; n < N; n++) {
        if (find(parent, n) != parent0) {
            cout << n + 1 << endl;
            valid = false;
        }
    }

    if (valid)
        cout << "Connected" << endl;

    return 0;
}