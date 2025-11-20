/*
*OpenKattis
*doctor kattis
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    // this is april 22, 2023
    // update from oct 30, 2023; hindi TLE if map, sobra lang ng operations/map (see new solution in 2324A newbb mock3)
    set <pair<int, int>> order; // infection, negative index
    // TLE if map only
    unordered_map <int, string> name; // index, name
    unordered_map <string, pair<int, int>> inf_idx; // name, infection, idx
    int index = 0;
    for (int n = 0; n < N; n++) {
        int Q;
        cin >> Q;
        if (Q == 0) {
            string n;
            int i;
            cin >> n >> i;
            order.insert(make_pair(i, -1*index));
            name[-1*index] = n;
            //idx[n] = -1*index;
            //infection[n] = i;
            inf_idx[n] = make_pair(i, -1*index);
            index++;
        } else if (Q == 1) {
            string n;
            int i;
            cin >> n >> i;
            auto it = order.find(inf_idx[n]);
            order.erase(it);

            inf_idx[n].first += i;
            order.insert(inf_idx[n]);
        } else if (Q == 2) {
            string n;
            cin >> n;
            auto it = order.find(inf_idx[n]);
            order.erase(it);
        } else { // Q == 3
            if (!order.empty()) {
                pair <int, int> illestcat = *(order.rbegin());
                string n = name[illestcat.second];
                cout << n << endl;
            } else
                cout << "The clinic is empty" << endl;
        }
    }
    return 0;
}