/*
*OpenKattis
*hopscotch50
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

int N, DIST = INF;

void backtracking (int i, int j, vector <pair <int, int>> dist[], int d, int count)
{
    if (count == 5) {
        DIST = min(DIST, d);
        return;
    }
    if (dist[j+i*N].empty())
        return;
    
    for (int k = 0; k < (int) dist[j+i*N].size(); k++)
        backtracking(dist[j+i*N][k].first/N, dist[j+i*N][k].first%10, dist, d + dist[j+i*N][k].second, count + 1);
}
int main ()
{
    int K;
    cin >> N >> K;

    int matrix[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];

    vector <pair <int, int>> dist[N*N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int i2 = 0; i2 < N; i2++) 
                for (int j2 = 0; j2 < N; j2++) {
                    if ((matrix[i2][j2] - matrix[i][j]) == 1) {
                        dist[j + N*i].push_back(make_pair(j2 + N*i2, abs(i - i2) + abs(j - j2)));
                    }
                }

    DIST = INF; 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1)
                backtracking(i,j,dist,0,1); // idk how to dp so backtrack tayo hahaha
        }

    if (DIST == INF)
        cout << -1 << endl;
    else
        cout << DIST << endl;
    return 0;
}