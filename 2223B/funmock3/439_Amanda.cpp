/*
*OnlineJudge
*439 - Knight Moves
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int main ()
{
    map <pair <int, int>, int> idx;
    int index = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            idx[make_pair(i, j)] = index;
            index++;
        }

    int V = 8*8;   
    vector <vector <int>> dist (V, vector <int> (V, INF));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            dist[idx[make_pair(i,j)]][idx[make_pair(i,j)]] = 0;
            for (int k = 0; k < 8; k++)
                if (idx.find(make_pair(i + dx[k],j + dy[k])) != idx.end())  
                    dist[idx[make_pair(i,j)]][idx[make_pair(i + dx[k], j + dy[k])]] = 1;
        }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if ((dist[k][j] != INF) && (dist[i][k] != INF) && (dist[i][j] > (dist[i][k] + dist[k][j])))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    string a, b;
    while (cin >> a >> b) {
        int xa = a[0] - 'a', xb = b[0] - 'a';
        int ya = a[1] - '0' - 1, yb = b[1] - '0' - 1;
        
        cout << "To get from " << a << " to " << b << " takes " << dist[idx[make_pair(xa,ya)]][idx[make_pair(xb,yb)]] << " knight moves." << endl;
    }
    return 0;
}