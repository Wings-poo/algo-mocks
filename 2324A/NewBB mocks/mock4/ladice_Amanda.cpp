/*
*OpenKattis
*ladice
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

int connect (int parent[], int saizu[], int content[], int roota, int rootb)
{
    if (roota == rootb)
        return roota;

    if (saizu[roota] < saizu[rootb])
        swap(roota, rootb);

    parent[rootb] = roota;
    saizu[roota] += saizu[rootb];
    saizu[rootb] = 0;
    content[roota] += content[rootb];

    return roota;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, L;
    cin >> N >> L;

    int parent[L + 1], saizu[L + 1], content[L + 1];
    for (int l = 0; l <= L; l++) {
        parent[l] = l;
        saizu[l] = 1;
        content[l] = 0;
    }

    for (int n = 0; n < N; n++) {
        int A, B;
        cin >> A >> B;

        int roota = find(parent, A);
        int rootb = find(parent, B);
        int root = connect(parent, saizu, content, roota, rootb);

        if (content[root] < saizu[root]) {
            content[root]++;
            cout << "LADICA" << endl;
        } else
            cout << "SMECE" << endl;
    }

    return 0;
}