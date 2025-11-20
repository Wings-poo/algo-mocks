/*
*OpenKattis
*mixedfractions
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// This problem is an endl filter

int find (int parent[], int x)
{
    if (x != parent[x])
        return parent[x] = find(parent, parent[x]);
    return x;
}

void connect (int parent[], int saizu[], int a, int b)
{
    int roota = find(parent, a);
    int rootb = find(parent, b);

    if (roota == rootb)
        return;

    if (saizu[roota] < saizu[rootb])
        swap(roota, rootb);

    saizu[roota] += saizu[rootb];
    parent[rootb] = roota;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    //scanf(" %i %i ", &N, &Q);

    int parent[N], saizu[N];
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        saizu[i] = 1;
    }

    for (int q = 0; q < Q; q++) {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        //scanf(" %c %i %i ", &cmd, &a, &b);

        if (cmd == '=')
            connect(parent, saizu, a, b);
        else {
            if (find(parent, a) == find(parent, b))
                cout << "yes\n"; //printf("yes\n");  // if endl, it goes TLE :D          
            else 
                cout << "no\n"; //printf("no\n");
        }
    }   
    return 0;
}