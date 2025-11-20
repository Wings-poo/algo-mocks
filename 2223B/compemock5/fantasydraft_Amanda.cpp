/*
*OpenKattis
*fantasydraft
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N, K;
    cin >> N >> K;

    vector <queue <string>> preferred (N);
    for (int n = 0; n < N; n++) {
        int Q;
        cin >> Q;
        for (int q = 0; q < Q; q++) {
            string player;
            cin >> player;
            preferred[n].push(player);
        }
    }

    int P;
    cin >> P;
    map <string, int> idx;
    vector <pair <string, bool>> players;
    for (int p = 0; p < P; p++) {
        string player;
        cin >> player;
        idx[player] = players.size();
        players.push_back(make_pair(player,false));
    }

    int curr_best = 0;
    vector <vector <string>> draft (N);
    for (int k = 0; k < K; k++) {
        for (int n = 0; n < N; n++) {
            bool drafted = false;
            while (!preferred[n].empty()) {
                string player = preferred[n].front();
                preferred[n].pop();

                if (players[idx[player]].second == false) {
                    players[idx[player]].second = true;
                    draft[n].push_back(player);

                    drafted = true;
                    break;
                }
            }
            
            if (!drafted) {
                while (players[curr_best].second == true)
                    curr_best++;

                draft[n].push_back(players[curr_best].first);
                players[curr_best].second = true;
                curr_best++;
            }
        }
    }

    for (int n = 0; n < N; n++) {
        for (int k = 0; k < K; k++)
            cout << draft[n][k] << " ";
        cout << endl;
    }
    return 0;
}