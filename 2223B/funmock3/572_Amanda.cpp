/*
*OnlineJudge
*572 - Oil Deposits
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

int find (int parent[], int A)
{
    if (parent[A] == A)
        return A;
    return find(parent, parent[A]);
}

void union_ (int parent[], int A, int B)
{
    parent[find(parent, A)] = parent[find(parent, B)];
    return;
}

int main ()
{
    int N, M;
    while (cin >> N >> M) {
        if (!M)
            break;
        
        map <pair <int, int>, int> idx;
        int index = 0;
        char grid[N][M];
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++) {
                cin >> grid[n][m];
                idx[make_pair(n,m)] = index;
                index++;
            }
        
        int parent[index];
        for (int i = 0; i < index; i++)
            parent[i] = i;

        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++) {
                if (grid[n][m] == '@') {
                    for (int k = 0; k < 8; k++) {
                        if ((n + dx[k] >= 0) && (n + dx[k] < N))
                            if ((m + dy[k] >= 0) && (m + dy[k] < M))
                                if (grid[n + dx[k]][m + dy[k]] == '@')
                                    union_(parent, idx[make_pair(n,m)], idx[make_pair(n + dx[k],m + dy[k])]);
                    }
                }
            }

        set <int> uniqueparent;
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++) {
                if (grid[n][m] == '@') {
                    uniqueparent.insert(find(parent, idx[make_pair(n,m)]));
                }
            }

        cout << uniqueparent.size() << endl;
    }
    return 0;
}