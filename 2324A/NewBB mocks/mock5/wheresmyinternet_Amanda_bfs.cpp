/*
*OpenKattis
*wheresmyinternet
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector <vector <int>> adj_list (N);
    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bool visited[N] = {0};
    queue <int> q;
    
    q.push(0);
    visited[0] = true;

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

    bool valid = true;
    for (int n = 0; n < N; n++)
        if (!visited[n]) {
            cout << n + 1 << endl;
            valid = false;
        }

    if (valid)
        cout << "CONNECTED" << endl;

    return 0;
}