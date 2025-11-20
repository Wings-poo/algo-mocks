/*
*CodeForces
*104064 - K. Knitpicking
*Code by: Amanda Lim
*/

// WA infinite loop/segfault - solution is math:
// num socks for the colors that can never pair + min socks needed to make at least one pair for each pairable color - num of pairable colors +1
// if 0 yung num of pairable colors, it's impossible

#include <bits/stdc++.h>
using namespace std;

int bt(vector <tuple <string, string, int>> socks, map <string, tuple <int, int, int>> curr_socks, int count, int sock_idx)
{
    cout << sock_idx << " " << get<1>(socks[sock_idx]) << " " << get<2>(socks[sock_idx]) << " " << count << endl;
    if (sock_idx == socks.size())
        return 0;

    cout << "um" << endl;
    if (curr_socks.find(get<0>(socks[sock_idx])) != curr_socks.end()) {
        if ((get<0>(curr_socks[get<0>(socks[sock_idx])]) && get<1>(curr_socks[get<0>(socks[sock_idx])])) ||
            (get<0>(curr_socks[get<0>(socks[sock_idx])]) && get<2>(curr_socks[get<0>(socks[sock_idx])])) ||
            (get<1>(curr_socks[get<0>(socks[sock_idx])]) && get<2>(curr_socks[get<0>(socks[sock_idx])])) ||
            (get<2>(curr_socks[get<0>(socks[sock_idx])]) == 2))
            return count;
    }

    if (get<2>(socks[sock_idx]) == 0)
        return 0;

    vector <tuple <string, string, int>> new_socks = socks;
    new_socks[sock_idx] = make_tuple(get<0>(socks[sock_idx]), get<1>(socks[sock_idx]), get<2>(socks[sock_idx]) - 1);
        
    map <string, tuple <int, int, int>> new_curr_socks = curr_socks;
    if (new_curr_socks.find(get<0>(socks[sock_idx])) != new_curr_socks.end()) {
        if (get<1>(socks[sock_idx]) == "right")
            new_curr_socks[get<0>(socks[sock_idx])] = make_tuple(get<0>(new_curr_socks[get<0>(socks[sock_idx])]) + 1, get<1>(new_curr_socks[get<0>(socks[sock_idx])]), get<2>(new_curr_socks[get<0>(socks[sock_idx])]));
        if (get<1>(socks[sock_idx]) == "left")
            new_curr_socks[get<0>(socks[sock_idx])] = make_tuple(get<0>(new_curr_socks[get<0>(socks[sock_idx])]), get<1>(new_curr_socks[get<0>(socks[sock_idx])]) + 1, get<2>(new_curr_socks[get<0>(socks[sock_idx])]));
        if (get<1>(socks[sock_idx]) == "any")
            new_curr_socks[get<0>(socks[sock_idx])] = make_tuple(get<0>(new_curr_socks[get<0>(socks[sock_idx])]), get<1>(new_curr_socks[get<0>(socks[sock_idx])]), get<2>(new_curr_socks[get<0>(socks[sock_idx])]) + 1);
    } else {
        if (get<1>(socks[sock_idx]) == "right")
            new_curr_socks[get<0>(socks[sock_idx])] = make_tuple(1, 0, 0);
        if (get<1>(socks[sock_idx]) == "left")
            new_curr_socks[get<0>(socks[sock_idx])] = make_tuple(0, 1, 0);
        if (get<1>(socks[sock_idx]) == "any")
            new_curr_socks[get<0>(socks[sock_idx])] = make_tuple(0, 0, 1);
    }

    cout << "yoloaofjqwioj" << endl;
    int maxbt = 0;
    for (int i = 0; i < (int) socks.size(); i++) {
        //int bt1 = 0;
        int bt1 = bt(new_socks, new_curr_socks, count + 1, i);
        cout << bt1 << endl;
        int bt2 = 0;
        //int bt2 = ;
        cout << "maxbt " << maxbt << " " << bt1 << " " << bt2 << endl;
        maxbt = max(maxbt, max(bt1, bt2));
    }

    return max(maxbt, bt(socks, curr_socks, count, sock_idx + 1));
}

int main()
{
    int N;
    cin >> N;

    vector <tuple <string, string, int>> socks (N);
    for (int n = 0; n < N; n++) {
        string type, group;
        int num_socks;
        cin >> type >> group >> num_socks;
        socks[n] = make_tuple(type, group, num_socks);
    }

    int ans = bt(socks, map <string, tuple <int, int, int>> (), 0, 0);

    if (ans)
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}