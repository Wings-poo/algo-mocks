/*
*OpenKattis
*gettowork
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "Case #" << t+1 << ": ";
        
        int N, O;           // O for Office
        cin >> N >> O;

        int E;
        cin >> E;

        map <int, int> employees;
        map <int, priority_queue <int>> cars;
        for (int i = 1; i <= N; i++) {
            priority_queue <int> empty;
            cars[i] = empty;
            employees[i] = 0;
        }

        for (int e = 0; e < E; e++) {
            int H, P;
            cin >> H >> P;
            cars[H].push(P);
            employees[H]++;
        }

        bool valid = true;
        vector <int> min_cars (N, 0);
        for (int i = 1; i <= N; i++) {
            if (i == O)
                continue;

            int min_car = 0;
            while ((employees[i] > 0) && (!cars[i].empty())) {
                employees[i] -= cars[i].top();
                cars[i].pop();
                min_car++;
            }

            if (employees[i] > 0)
                valid = false;

            min_cars[i-1] = min_car;
        }

        if (valid)
            for (int i = 0; i < N; i++)
                cout << min_cars[i] << " ";
        else 
            cout << "IMPOSSIBLE";
        
        cout << endl;
    }
    return 0;
}