// WA
/*
*OpenKattis
*martensdfs
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int idx = 1;
bool dfs (int start, vector <int> neighbors[], bool seen[], vector <int> sequence)
{
    seen[start] = true;
    for (int i = 0; i < (int) neighbors[start].size(); i++) {
        if ((neighbors[start][i] == sequence[idx]) && !seen[neighbors[start][i]]) {
            if (idx == (int) sequence.size() - 1)
                return true;
            else {
                idx++;
                return dfs(sequence[idx], neighbors, seen, sequence);
            }
        }
    }


    return false;
}

int main ()
{
    int N, E;
    cin >> N >> E;

    vector <int> neighbors[N];
    for (int e = 0; e < E; e++) {
        int a, b;
        cin >> a >> b;

        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    getchar();
    string s;
    getline(cin, s);
    stringstream ss(s);

    vector <int> sequence;
    int num;
    while (ss >> num)
        sequence.push_back(num);
    
    int valid = true;
    if ((int) sequence.size() == N) {
        if (sequence[0] < N) {
            bool seen[N] = {0};
            valid = dfs(sequence[0], neighbors, seen, sequence);
        } else
            valid = false;
    } else
        valid = false;

    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}