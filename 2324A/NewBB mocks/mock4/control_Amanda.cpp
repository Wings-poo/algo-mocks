/*
*OpenKattis
*control
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

    if (roota == rootb)
        return;

    if (saizu[roota] < saizu[rootb])
        swap(roota, rootb);

    parent[rootb] = roota;
    saizu[roota] += saizu[rootb];
    saizu[rootb] = 0;

    return;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    int parent[500001];
    int saizu[500001];
    for (int i = 0; i <= 500000; i++) {
        parent[i] = i;
        saizu[i] = 1;
    }
    
    int potion = 0;
    for (int n = 0; n < N; n++) {
        int M;
        cin >> M;

        int ingredients[M];
        set <int> pastparent;
        for (int m = 0; m < M; m++) {
            cin >> ingredients[m];
            int parentm = find(parent, ingredients[m]);
            pastparent.insert(parentm);
        }

        int totalsize = 0;
        for (auto i : pastparent)
            totalsize += saizu[i];
        
        if (totalsize == M) {
            int first_ing = ingredients[0];
            for (int m = 1; m < M; m++)
                connect(parent, saizu, first_ing, ingredients[m]);
            potion++;
        }
    }

    cout << potion << endl;

    return 0;
}