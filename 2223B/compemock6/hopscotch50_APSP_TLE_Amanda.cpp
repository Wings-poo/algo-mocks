/*
*OpenKattis
*hopscotch50
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

int main ()
{
    int N, K;
    cin >> N >> K;

    int matrix[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];

    int V = N*N;
    int dist[V][V];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int i2 = 0; i2 < N; i2++) 
                for (int j2 = 0; j2 < N; j2++) {
                    if (abs(matrix[i][j] - matrix[i2][j2]) != 1) {
                        dist[j + N*i][j2 + N*i2] = INF;
                        dist[j2 + N*i2][j + N*i] = INF;
                    }
                    else {
                        dist[j + N*i][j2 + N*i2] = abs(i - i2) + abs(j - j2);
                        dist[j2 + N*i2][j + N*i] = abs(i - i2) + abs(j - j2);
                    }
                }

    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if ((dist[i][j] > (dist[i][k] + dist[k][j]))
                        && (dist[k][j] != INF) && (dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int DIST = INF;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int i2 = i; i2 < N; i2++)
                for (int j2 = j; j2 < N; j2++) {
                    if ((matrix[i][j]  == 1) && (matrix[i2][j2]  == 5))
                        DIST = min(DIST, dist[j + N*i][j2 + N*i2]);
                    if ((matrix[i][j]  == 5) && (matrix[i2][j2]  == 1))
                        DIST = min(DIST, dist[j + N*i][j2 + N*i2]);
                }
    
    if (DIST == INF)
        cout << -1 << endl;
    else
        cout << DIST << endl;
    return 0;
}