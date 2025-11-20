/*
*OpenKattis
*reachableroads
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

void connect (int parent[], int saizu[], int A, int B)
{
    int rootA = find(parent, A);
    int rootB = find(parent, B);

    if (rootA == rootB)
        return;

    if (saizu[rootA] < saizu[rootB])
        swap(rootA, rootB);

    parent[rootB] = rootA;
    saizu[rootA] += saizu[rootB];
    saizu[rootB] = 0;

    return;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int M;
        cin >> M;

        int parent[M], saizu[M];
        for (int m = 0; m < M; m++) {
            parent[m] = m;
            saizu[m] = 1;
        }

        int R;
        cin >> R;
        for (int r = 0; r < R; r++) {
            int a, b;
            cin >> a >> b;
            connect(parent, saizu, a, b);
        }

        set <int> parents;
        for (int m = 0; m < M; m++)
            parents.insert(find(parent,parent[m]));

        cout << parents.size() - 1 << endl;
    }

    return 0;
}