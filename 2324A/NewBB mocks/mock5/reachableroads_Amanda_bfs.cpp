/*
*OpenKattis
*reachableroads
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

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

        int R;
        cin >> R;

        vector <vector <int>> adj_list (M);
        for (int r = 0; r < R; r++) {
            int a, b;
            cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        bool visited[M] = {0};
        int ans = 0;
        for (int m = 0; m < M; m++) {
            if (visited[m])
                continue;

            ans++;

            // BFS
            queue <int> q;
            q.push(m);

            while(!q.empty()) {
                // Get the front of the queue
                int u = q.front(); q.pop();

                // For every neighbor v of u...
                for (auto v: adj_list[u]) {
                    if (visited[v])
                        continue;

                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << ans - 1 << endl;
    }

    return 0;
}