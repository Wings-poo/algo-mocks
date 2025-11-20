/*
*OpenKattis
*countingstars
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 1;
    int N, M;
    while (cin >> N >> M) {
        map <pair <int, int>, int> idx;
        vector <vector <int>> adj_list (N*M);

        char grid[N][M];
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++) {
                idx[{n,m}] = idx.size();
                cin >> grid[n][m];
            }

        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++)
                if (grid[n][m] == '-') 
                    for (int i = 0; i < 4; i++) 
                        if (((n + dx[i]) >= 0) && ((n + dx[i]) < N) && ((m + dy[i]) >= 0) && ((m + dy[i]) < M))
                            if (grid[n + dx[i]][m + dy[i]] == '-') {
                                adj_list[idx[{n,m}]].push_back(idx[{n + dx[i], m + dy[i]}]);
                                adj_list[idx[{n + dx[i], m + dy[i]}]].push_back(idx[{n,m}]);
                            }
        
        int ans = 0;
        bool visited[N*M] = {0};
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++) {
                if (grid[n][m] == '#')
                    continue;

                if (visited[idx[{n,m}]])
                    continue;

                ans++;

                queue <int> q;
                q.push(idx[{n,m}]);
                visited[idx[{n,m}]] = true;

                while (!q.empty()) {
                    auto u = q.front();
                    q.pop();

                    for (auto v : adj_list[u]) {
                        if (visited[v])
                            continue;

                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

        cout << "Case " << T++ << ": " << ans << endl;

    }

    return 0;
}